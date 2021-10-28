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


static char	*ft_check_ost(char *ost, char **res, int n_read)
{
	char	*p_n;
	p_n = ft_strchr(ost, '\n');
	if (p_n)
	{
		*p_n = '\0';
		*res = ft_strdup(ost);
		*res = ft_strjoin(*res, "\n");
		p_n++;
		if (*p_n != '\0')
			ost = p_n;
		else
			ost = NULL;
	}
	else if (!p_n && n_read == 0)
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
	int			n_read;

	res = NULL;
	while (!res)
	{
		n_read = read(fd, &buf, BUFFER_SIZE);
		buf[n_read] = '\0';
		if (n_read > 0)
		{
			if (ost)
				ost = ft_strjoin(ost, buf);
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

//  int main()
// {
// 	int fd;
// 	fd = open("test.txt", O_RDONLY);
// 	printf("res = %s", get_next_line(fd));
// 	printf("res = %s", get_next_line(fd));
// 	printf("res = %s", get_next_line(fd));
// 	printf("res = %s", get_next_line(fd));
// 	printf("res = %s", get_next_line(fd));
// 	printf("res = %s", get_next_line(fd));
// 	printf("res = %s", get_next_line(fd));
// 	printf("res = %s", get_next_line(fd));
// 	printf("res = %s", get_next_line(fd));
// }
