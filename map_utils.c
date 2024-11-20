/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:35:01 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 11:54:37 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

int	calc_max_level(t_map *map)
{
	int	ret;
	int	i;
	int	j;

	ret = 1;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] > ret)
				ret = map->grid[i][j];
			j++;
		}
		i++;
	}
	return (ret);
}

void	free_map(t_map *map, int count)
{
	int	i;

	i = 0;
	while (i < map->height && i < count)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}
