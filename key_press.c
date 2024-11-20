/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:01:16 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 10:25:55 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press_zoom(int keycode, t_vars *vars)
{
	if (keycode == 122)
	{
		vars->scale += (int)(WIN_HEIGHT / vars->map->height / 10);
		vars->height_scale += (int)(WIN_HEIGHT / vars->map->max_level / 40);
		if ((int)(WIN_HEIGHT / vars->map->height / 10) == 0)
			vars->scale += 1;
		if (vars->height_scale == 0)
			vars->height_scale = 1;
		draw_image(vars);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img_data->img,
			0, 0);
	}
	if (keycode == 120)
	{
		vars->scale -= (int)(WIN_HEIGHT / vars->map->height / 10);
		vars->height_scale -= (int)(WIN_HEIGHT / vars->map->max_level / 40);
		if ((int)(WIN_HEIGHT / vars->map->height / 10) == 0)
			vars->scale -= 1;
		if (vars->height_scale == 0)
			vars->height_scale = 1;
		draw_image(vars);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img_data->img,
			0, 0);
	}
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		close_window(vars);
	}
	if (keycode == 32)
	{
		vars->conical_mode = 1 - vars->conical_mode;
		draw_image(vars);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img_data->img,
			0, 0);
	}
	key_press_zoom(keycode, vars);
	key_press_translate(keycode, vars);
	return (0);
}
