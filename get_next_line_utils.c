/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:06:28 by sazelda           #+#    #+#             */
/*   Updated: 2021/10/25 18:25:55 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2, size_t *size_ost)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;
	size_t			len_s1;
	size_t			len_s2;

	if (!s1)
		return ((void *)0);
	i = 0;
	len_s1 = *size_ost;
	len_s2 = ft_strlen(s2);
	res = (char *)malloc(len_s1 + len_s2 + 1);
	if (!res)
		return ((void *)0);
	while (i < len_s1)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	*size_ost = len_s1 + len_s2;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return ((void *)0);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	i = 0;
	d = dst;
	s = src;
	if (d == s)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1, size_t size_ost)
{
	char	*res;
	//size_t	size;

	res = malloc(size_ost + 1);
	if (!res)
		return ((void *)0);
	ft_memcpy(res, s1, size_ost + 1);
	return (res);
}
