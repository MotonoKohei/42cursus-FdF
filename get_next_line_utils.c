/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:32:29 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 09:40:53 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(s);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s, len);
	dest[len] = '\0';
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*_dest;
	const unsigned char	*_src;

	if (!dest || !src)
		return (NULL);
	_dest = dest;
	_src = src;
	while (n--)
		*_dest++ = *_src++;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr;

	if (!s1)
		len_s1 = 0;
	else
		len_s1 = ft_strlen(s1);
	if (!s2)
		len_s2 = 0;
	else
		len_s2 = ft_strlen(s2);
	ptr = (char *)malloc(len_s1 + len_s2 + 1);
	if (!ptr)
		return (NULL);
	if (s1)
		ft_memcpy(ptr, s1, len_s1);
	if (s2)
		ft_memcpy(ptr + len_s1, s2, len_s2);
	ptr[len_s1 + len_s2] = '\0';
	return (ptr);
}
