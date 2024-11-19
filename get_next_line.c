/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:31:36 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/19 21:33:29 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

static int	read_to_remainder(int fd, char **remainder);
static char	*extract_line_from_remainder(char **remainder);
static char	*cleanup_remainder(char **remainder);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_to_remainder(fd, &remainder) == -1)
		return (NULL);
	line = extract_line_from_remainder(&remainder);
	if (line)
		return (line);
	return (cleanup_remainder(&remainder));
}

static int	read_to_remainder(int fd, char **remainder)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	if (*remainder == NULL)
		*remainder = ft_strdup("");
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = 0;
	while (ft_strchr(*remainder, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*remainder, buffer);
		free(*remainder);
		*remainder = temp;
	}
	free(buffer);
	if (bytes_read == -1)
		return (-1);
	return (0);
}

static char	*extract_line_from_remainder(char **remainder)
{
	char	*newline;
	char	*line;
	char	*temp;
	size_t	line_len;

	newline = ft_strchr(*remainder, '\n');
	if (newline)
	{
		line_len = newline - *remainder + 1;
		line = (char *)malloc(line_len + 1);
		if (!line)
			return (NULL);
		ft_memcpy(line, *remainder, line_len);
		line[line_len] = '\0';
		temp = ft_strdup(newline + 1);
		free(*remainder);
		*remainder = temp;
		return (line);
	}
	return (NULL);
}

static char	*cleanup_remainder(char **remainder)
{
	char	*line;

	if (*remainder && **remainder)
	{
		line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
		return (line);
	}
	free(*remainder);
	*remainder = NULL;
	return (NULL);
}
