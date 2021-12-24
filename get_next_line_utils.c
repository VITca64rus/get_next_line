/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:06:28 by sazelda           #+#    #+#             */
/*   Updated: 2021/12/24 13:53:52 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2, \
					size_t *size_ost, size_t len_s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	if (!s1)
		return ((void *)0);
	i = 0;
	res = (char *)malloc(*size_ost + len_s2 + 1);
	if (!res)
		return ((void *)0);
	while (i < *size_ost)
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
	*size_ost = *size_ost + len_s2;
	return (res);
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

	res = malloc(size_ost + 1);
	if (!res)
		return ((void *)0);
	ft_memcpy(res, s1, size_ost + 1);
	return (res);
}
