/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:06:31 by sazelda           #+#    #+#             */
/*   Updated: 2021/12/02 13:21:20 by sazelda          ###   ########.fr       */
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
	//char	*p_n;
	int id_n;
	//char		*for_free;
	int i;
	id_n = find_n(ost);
	//p_n = ft_strchr(ost, '\n');
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
			ost = &ost[i];
		else
			ost = NULL;
	}
	else if (id_n == -1 && n_read == 0)
	{
		*res = ft_strdup(ost);
		ost = NULL;
	}
	//printf("OSt = %s\n", ost);
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
			{
				ost = ft_strdup(buf);
			}
		}
		else if (n_read == 0)
		{
			if (ost)
			{
				ost = ft_check_ost(ost, &res, n_read);
				if (res)
				{
					free(ost);
					return (res);
				}
			}
			else
			{
				free(ost);
				free(res);
				return (NULL);
			}
		}
		else
		{
			return (NULL);
		}
		ost = ft_check_ost(ost, &res,n_read);
	}
	free(ost);
	return (res);
}

//  int main()
// {
// 	int fd;
// 	fd = open("test.txt", O_RDONLY);
// 	printf("res = %s", get_next_line(fd));
// }
