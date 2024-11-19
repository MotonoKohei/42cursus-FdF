/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_translate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 07:43:14 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 07:46:18 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_up(t_vars *vars)
{
	vars->translate_i -= vars->win_height / 20;
	draw_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img_data->img, 0,
		0);
}

void	translate_down(t_vars *vars)
{
	vars->translate_i += vars->win_height / 20;
	draw_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img_data->img, 0,
		0);
}

void	translate_right(t_vars *vars)
{
	vars->translate_j += vars->win_width / 20;
	draw_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img_data->img, 0,
		0);
}

void	translate_left(t_vars *vars)
{
	vars->translate_j -= vars->win_width / 20;
	draw_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img_data->img, 0,
		0);
}

int	key_press_translate(int keycode, t_vars *vars)
{
	if (keycode == 65362)
		translate_up(vars);
	else if (keycode == 65364)
		translate_down(vars);
	else if (keycode == 65363)
		translate_right(vars);
	else if (keycode == 65361)
		translate_left(vars);
	return (0);
}
