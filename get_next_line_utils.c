#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const s2)
{
	char			*res;
	unsigned int	i;

	if (!s1)
		return ((void *)0);
	i = 0;
	res = (char *)malloc(ft_strlen(s1) + 1 + 1);
	if (!res)
		return ((void *)0);
	while (i < ft_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = s2;
	i++;
	res[i] = '\0';
	return (res);
}