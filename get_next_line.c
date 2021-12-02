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
	//char	*p_n;
	int id_n;
	//char		*for_free;
	int i;
	char *tmp;
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
		{
			tmp = ost;
			ost = malloc(ft_strlen(ost)-id_n+1);
			i = 0;
			while (id_n < (int)ft_strlen(tmp))
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
					if (ost && ost[0] != '\n')
						free(ost);
					return (res);
				}
			}
			else
			{
				//free(ost);kmmkkmmk
				// free(res);
				return (NULL);
			}
		}
		else
		{
			return (NULL);
		}
		ost = ft_check_ost(ost, &res,n_read);
	}
	//free(ost);
	return (res);
}

 int main()
{
	int fd;
	
	fd = open("text.txt", O_RDONLY);
	printf("res1 = %s", get_next_line(fd));
	printf("res2 = %s", get_next_line(fd));
	printf("res3 = %s", get_next_line(fd));
	printf("res4 = %s", get_next_line(fd));
	printf("res5 = %s", get_next_line(fd));
	printf("res6 = %s", get_next_line(fd));
	printf("res7 = %s", get_next_line(fd));
	printf("res8 = %s", get_next_line(fd));
	printf("res9 = %s", get_next_line(fd));
	printf("res10 = %s", get_next_line(fd));
}