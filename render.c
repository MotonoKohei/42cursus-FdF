/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:04:25 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 08:05:27 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_points_and_draw(t_vars *vars, t_point *point1, t_point *point2)
{
	scale_point(vars, point1);
	scale_point(vars, point2);
	rotate_point_3d(vars, point1);
	rotate_point_3d(vars, point2);
	if (vars->conical_mode)
	{
		convert_to_conical(vars, point1);
		convert_to_conical(vars, point2);
	}
	translate_point(vars, point1);
	translate_point(vars, point2);
	draw_image_line(vars, point1, point2);
}

void	draw_cell_lines(t_vars *vars, int i, int j)
{
	t_point	point1;
	t_point	point2;

	if (i > 0)
	{
		init_point(&point1, i - 1, j, vars->map->grid[i - 1][j]);
		init_point(&point2, i, j, vars->map->grid[i][j]);
		process_points_and_draw(vars, &point1, &point2);
	}
	if (j > 0)
	{
		init_point(&point1, i, j - 1, vars->map->grid[i][j - 1]);
		init_point(&point2, i, j, vars->map->grid[i][j]);
		process_points_and_draw(vars, &point1, &point2);
	}
}

void	draw_image(t_vars *vars)
{
	int	i;
	int	j;

	clear_image(vars, 0x000000);
	i = -1;
	while (++i < vars->map->height)
	{
		j = -1;
		while (++j < vars->map->width)
		{
			draw_cell_lines(vars, i, j);
		}
	}
}

void	clear_image(t_vars *vars, int color)
{
	int				total_bytes;
	unsigned int	*pixel;
	int				pixel_count;
	int				i;

	if (!vars || !vars->img_data || !vars->img_data->addr)
		return ;
	total_bytes = vars->win_height * vars->img_data->line_length;
	pixel = (unsigned int *)vars->img_data->addr;
	pixel_count = total_bytes / (vars->img_data->bits_per_pixel / 8);
	i = 0;
	while (i < pixel_count)
	{
		pixel[i] = color;
		i++;
	}
}
