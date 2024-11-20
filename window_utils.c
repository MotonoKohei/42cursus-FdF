/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:14:38 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 12:00:49 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_window(t_vars *vars)
{
	vars->mlx_win = mlx_new_window(vars->mlx, vars->win_width, vars->win_height,
			"FdF");
	if (!vars->mlx_win)
		handle_error("Error: Failed to create a window\n");
}

void	allocate_image_data(t_vars *vars)
{
	vars->img_data = (t_data *)malloc(sizeof(t_data));
	if (!vars->img_data)
	{
		if (vars->mlx_win)
			mlx_destroy_window(vars->mlx, vars->mlx_win);
		handle_error("Error: Failed to allocate memory for image data\n");
	}
}

void	create_image(t_vars *vars)
{
	vars->img_data->img = mlx_new_image(vars->mlx, vars->win_width,
			vars->win_height);
	if (!vars->img_data->img)
	{
		if (vars->mlx_win)
			mlx_destroy_window(vars->mlx, vars->mlx_win);
		free(vars->img_data);
		handle_error("Error: Failed to create an image\n");
	}
}

void	get_image_data_address(t_vars *vars)
{
	vars->img_data->addr = mlx_get_data_addr(vars->img_data->img,
			&vars->img_data->bits_per_pixel, &vars->img_data->line_length,
			&vars->img_data->endian);
	if (!vars->img_data->addr)
	{
		if (vars->mlx_win)
			mlx_destroy_window(vars->mlx, vars->mlx_win);
		free(vars->img_data);
		handle_error("Error: Failed to get image data address\n");
	}
}
