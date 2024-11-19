/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 07:54:48 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 07:56:43 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

void	parse_line_to_row(char *line, int *row, int width)
{
	char	**nums;
	int		j;

	j = 0;
	nums = ft_split(line, ' ');
	while (nums[j])
	{
		if (j >= width)
		{
			fprintf(stderr,
				"Error: Line contains more columns than expected\n");
			exit(EXIT_FAILURE);
		}
		row[j] = ft_atoi(nums[j]);
		free(nums[j]);
		j++;
	}
	if (j != width)
	{
		fprintf(stderr, "Error: Line contains fewer columns than expected\n");
		exit(EXIT_FAILURE);
	}
	free(nums);
}

void	parse_file(const char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open_file(filename);
	line = get_next_line(fd);
	while (line)
	{
		if (i >= map->height)
		{
			fprintf(stderr, "Error: File contains more rows than expected\n");
			exit(EXIT_FAILURE);
		}
		parse_line_to_row(line, map->grid[i], map->width);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	if (i != map->height)
	{
		fprintf(stderr, "Error: File contains fewer rows than expected\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
}
