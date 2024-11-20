/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 07:54:48 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 10:05:52 by kmotono          ###   ########.fr       */
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
	while (nums[j] && j < width)
	{
		row[j] = ft_atoi(nums[j]);
		free(nums[j]);
		j++;
	}
	if (j != width)
		handle_error("Error: Line contains fewer columns than expected\n");
	free(nums);
}

// void	parse_line_to_row(char *line, int *row, int width)
// {
// 	char	**nums;
// 	int		j;

// 	j = 0;
// 	nums = ft_split(line, ' ');
// 	while (nums[j])
// 	{
// 		if (j >= width)
// 			handle_error("Error: Line contains more columns than expected\n");
// 		row[j] = ft_atoi(nums[j]);
// 		free(nums[j]);
// 		j++;
// 	}
// 	if (j != width)
// 		handle_error("Error: Line contains fewer columns than expected\n");
// 	free(nums);
// }

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
			handle_error("Error: File contains more rows than expected\n");
		parse_line_to_row(line, map->grid[i], map->width);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	if (i != map->height)
		handle_error("Error: File contains fewer rows than expected\n");
	close(fd);
}
