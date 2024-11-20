/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:09:10 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 10:15:19 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	validate_input(int argc)
{
	if (argc != 2)
	{
		write(1, "Invalid Input\n", 14);
		exit(EXIT_FAILURE);
	}
}

void	initialize_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		write(1, "Error: Failed to initialize MiniLibX\n", 37);
		exit(EXIT_FAILURE);
	}
}

void	initialize_vars(t_vars *vars, t_map *map, const char *filename)
{
	vars->map = map;
	init_map(filename, vars->map);
	parse_file(filename, vars->map);
	vars->map->max_level = calc_max_level(vars->map);
	vars->win_height = WIN_HEIGHT;
	vars->win_width = WIN_WIDTH;
	vars->scale = WIN_HEIGHT / vars->map->height / 2;
	if (vars->scale == 0)
		vars->scale = 1;
	vars->height_scale = WIN_HEIGHT / vars->map->max_level / 8;
	if (vars->height_scale == 0)
		vars->height_scale = 1;
	vars->angle_i = 0.525;
	vars->angle_j = -0.625;
	vars->angle_k = -0.6;
	vars->translate_i = vars->win_height / 2;
	vars->translate_j = vars->win_width / 2;
	vars->is_dragging = 0;
	vars->conical_mode = 0;
}
