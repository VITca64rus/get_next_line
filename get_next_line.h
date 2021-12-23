/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:06:21 by sazelda           #+#    #+#             */
/*   Updated: 2021/12/02 12:41:35 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define BUFFER_SIZE 42
# include <stdlib.h>


char	*ft_strjoin(char const *s1, char const *s2, size_t *size_ost, size_t len_s2);
char	*ft_strdup(const char *s1, size_t size_ost);
char	*get_next_line(int fd);


#endif