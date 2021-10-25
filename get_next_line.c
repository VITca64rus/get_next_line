/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:06:31 by sazelda           #+#    #+#             */
/*   Updated: 2021/10/25 19:37:33 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>


char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*p_n = NULL;
	static char 	*ost;
	char *res = NULL;
	char *tmp;
	int n_read;
	
	//printf("ost = %s", ost);
	while (!p_n && !res)
	{
		if (ost)
			p_n = ft_strchr(ost, '\n');
		//printf("ost = %s\n", ost);
		if (p_n)
		{
			*p_n = '\0';
			res = ost;

			ost = ++p_n;
			if (ost[0] == '\0')
			{
				ost = NULL;
				return (NULL);
			}
			if (res[0] == '\0')
				return ("\n");
			return (res);
		}
		else
		{
			n_read = read(fd, &buf, BUFFER_SIZE);
			if (n_read > 0)
			{
				buf[n_read] = '\0';
				//printf("BUF=%s\n", buf);
				//printf("%s", ost);
				if (!ost)
				{
					ost = malloc(2);
					ost[0] = '\0';
				}
				tmp = ost;
				ost = ft_strjoin(ost, buf);
				free(tmp);
			}
			else if (n_read == 0)
			{
				ost = ft_strjoin(ost, "\n");
			}
			else if (n_read < 0)
			{
				return (NULL);
			}
		}
	}
	//printf("LAST ost = %s", ost);
	return (res);
}

// int main()
// {
// 	int fd;
// 	fd = open("test.txt", O_RDONLY);
// 	printf("res = %s\n", get_next_line(fd));
// 	printf("res = %s\n", get_next_line(fd));
// }
