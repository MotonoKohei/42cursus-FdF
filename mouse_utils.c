/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:37:24 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 07:01:14 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int button, int j, int i, t_vars *vars)
{
	if (button == 1)
	{
		vars->is_dragging = 1;
		vars->prev_i = i;
		vars->prev_j = j;
	}
	return (0);
}

int	mouse_release(int button, int j, int i, t_vars *vars)
{
	(void)j;
	(void)i;
	if (button == 1)
	{
		vars->is_dragging = 0;
	}
	return (0);
}

int	mouse_move(int j, int i, t_vars *vars)
{
	int	di;
	int	dj;

	if (vars->is_dragging)
	{
		dj = j - vars->prev_j;
		di = i - vars->prev_i;
		vars->angle_j += di * 0.01;
		vars->angle_i += dj * 0.01;
		if (vars->angle_i > 90)
			vars->angle_i = 90;
		if (vars->angle_i < -90)
			vars->angle_i = -90;
		vars->prev_j = j;
		vars->prev_i = i;
		draw_image(vars);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img_data->img,
			0, 0);
	}
	return (0);
}
