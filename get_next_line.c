#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>


char	*get_next_line(int fd)
{
	char	buf[2 + 1];
	int	flag;
	char	*p_n;
	static char 	*ost;
	char *res;
	int n_read;
	if (!ost)
	{
		
		res = malloc(1);
		res[0] = '\0';
		p_n = NULL;
	}
	else
	{
		
		res = ft_strdup(ost);
		free(ost);
	}
	
	ost = NULL;
	p_n = NULL;
	n_read = read(fd, &buf, 2);
	//printf("BUF = %s\n", buf);
	while (!p_n && n_read)
	{
		p_n = ft_strchr(buf, '\n');
		if (p_n)
		{
			*p_n = '\0';
			ost = ft_strdup(++p_n);
			res = ft_strjoin(res, buf);
		}
		else
		{
			res = ft_strjoin(res, buf);
			n_read = read(fd, &buf, 2);
		}
	}
	res = ft_strjoin(res, "\n");
	return (res);
}

int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}