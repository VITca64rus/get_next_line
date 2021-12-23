/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:26:15 by chorse            #+#    #+#             */
/*   Updated: 2021/12/02 16:09:55 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

int	find_n(char *ost)
{
	int i;
	i = 0;
	while(ost[i] != '\0')
	{
		if (ost[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

static char	*ft_check_ost(char *ost, char **res, int n_read)
{
	int		id_n;
	int		i;
	char	*tmp;
	int		len_tmp;

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
			ost = malloc(ft_strlen(ost)-id_n+1);
			i = 0;
			len_tmp = (int)ft_strlen(tmp);
			while (id_n < len_tmp)
			{
				ost[i] = tmp[id_n];
				i++;
				id_n++;
			}
			ost[i] = '\0';
			free(tmp);
		}
		else
		{
			free(ost);
			return (NULL);
		};
	}
	else if (id_n == -1 && n_read == 0)
	{
		*res = ft_strdup(ost);
		if (ost)
			free(ost);
		ost = NULL;
		return (NULL);
	}
	return(ost);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*res;
	static char	*ost;
	char		*for_free;
	int			n_read;

	res = NULL;
	while (!res)
	{
		n_read = read(fd, &buf, BUFFER_SIZE);
		buf[n_read] = '\0';
		if (n_read > 0)
		{
			if (ost)
			{
				for_free = ost;
				ost = ft_strjoin(ost, buf);
				free(for_free);
			}
			else
				ost = ft_strdup(buf);
		}
		else if (n_read == 0)
		{
			if (ost)
			{
				ost = ft_check_ost(ost, &res, n_read);
				if (res)
					return (res);
			}
			else
				return (NULL);
		}
		else
			return (NULL);
		ost = ft_check_ost(ost, &res,n_read);
	}
	return (res);
}
