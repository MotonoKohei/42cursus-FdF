/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:33:48 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/19 21:33:57 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	strlen_separator(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*word_sep(const char *s, char c)
{
	int		i;
	int		len;
	char	*ret;

	len = strlen_separator(s, c);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static void	*free_all(char **ret, int j)
{
	while (j > 0)
		free(ret[--j]);
	free(ret);
	return (NULL);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	char	**ret;

	if (!s)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		ret[j] = word_sep(&s[i], c);
		if (!ret[j])
			return (free_all(ret, j));
		i += strlen_separator(&s[i], c);
		j++;
	}
	ret[j] = NULL;
	return (ret);
}
