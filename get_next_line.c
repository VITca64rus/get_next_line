#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buf;
	char	*res;

	read(fd, &buf, 1);
	while (buf != '\n')
	{
		res = ft_strjoin(res, buf);
		printf("%s", res);
		read(fd, &buf, 1);
	}
	res = ft_strjoin(res, '\n');
	return (res);
}

int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}