#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>


char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*p_n;
	static char 	*ost;
	char *res;
	int n_read;
	char	*tmp;

	p_n = NULL;
	
	if (!ost)
	{
		res = malloc(1);
		res[0] = '\0';
	}
	else
	{
		p_n = ft_strchr(ost, '\n');
		if (p_n)
		{
			*p_n = '\0';
			res = ft_strdup(ost);
			p_n++;
			ost = p_n;
		}
		else
		{
			res = ft_strdup(ost);
			ost = NULL;
		}
	}

	n_read = read(fd, &buf, BUFFER_SIZE);
	if (n_read < 0)
	{
		if (res)
			free(res);
		if (ost)
			free(ost);
		return (NULL);
	}
	buf[n_read] = '\0';

	while (!p_n && n_read)
	{
		p_n = ft_strchr(buf, '\n');
		if (p_n)
		{
			*p_n = '\0';
			ost = ft_strdup(++p_n);
			tmp = res;
			res = ft_strjoin(res, buf);
			if (tmp)
				free(tmp);
		}
		else
		{
			tmp = res;
			res = ft_strjoin(res, buf);
			free(tmp);
			n_read = read(fd, &buf, BUFFER_SIZE);
			if (n_read < 0)
			{
				if (res)
					free(res);
				if (ost)
					free(ost);
				return (NULL);
			}
			buf[n_read] = '\0';
		}
	}
	if (p_n)
		tmp = res;
		res = ft_strjoin(res, "\n");
		if (tmp)
			free(tmp);
	return (res);
}
