/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:26:15 by chorse            #+#    #+#             */
/*   Updated: 2021/12/24 14:25:20 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>
#include <time.h>

int	find_n(char *ost)
{
	int	i;

	i = 0;
	while (ost[i] != '\0')
	{
		if (ost[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

static char	*ft_check_ost(char *ost, char **res, int n_read, size_t *size_ost)
{
	int		id_n;
	int		i;
	char	*tmp;

	id_n = find_n(ost);
	if (id_n != -1)
	{
		*res = (char *)malloc(id_n + 1);
		i = 0;
		while (i < id_n)
		{
			(*res)[i] = ost[i];
			i++;
		}
		(*res)[i] = '\0';
		if (ost[i] != '\0')
		{
			tmp = ost;
			*size_ost = (*size_ost) - id_n;
			ost = ft_strdup(&ost[id_n], *size_ost);
			free(tmp);
		}
		else
		{
			free(ost);
			return (NULL);
		}
	}
	else if (id_n == -1 && n_read == 0)
	{
		*res = ft_strdup(ost, *size_ost);
		if (ost)
			free(ost);
		ost = NULL;
		return (NULL);
	}
	return (ost);
}

void	ft_make_ost(char **ost, char *buf, size_t *size_ost, int n_read)
{
	char	*for_free;

	if (*ost)
	{
		for_free = *ost;
		*ost = ft_strjoin(*ost, buf, size_ost, n_read);
		free(for_free);
	}
	else
	{
		*size_ost = n_read;
		*ost = ft_strdup(buf, *size_ost);
	}
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	char			*res;
	static char		*ost;
	static size_t	size_ost;
	int				n_read;

	res = NULL;
	while (!res)
	{
		n_read = read(fd, &buf, BUFFER_SIZE);
		buf[n_read] = '\0';
		if (n_read > 0)
			ft_make_ost(&ost, buf, &size_ost, n_read);
		else if (n_read == 0)
		{
			if (ost)
			{
				ost = ft_check_ost(ost, &res, n_read, &size_ost);
				if (res)
					return (res);
			}
			else
				return (NULL);
		}
		else
			return (NULL);
		ost = ft_check_ost(ost, &res, n_read, &size_ost);
	}
	return (res);
}
