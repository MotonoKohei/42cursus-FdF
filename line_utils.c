/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:51:10 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 08:51:47 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_line_params_low(t_line_params *params, t_point *point1,
		t_point *point2)
{
	params->di = point2->i - point1->i;
	params->dj = point2->j - point1->j;
	params->increment = 1;
	if (params->di < 0)
	{
		params->increment = -1;
		params->di = -(params->di);
	}
	params->adjustment = 2 * params->di - params->dj;
	params->i = point1->i;
	params->j = point1->j;
	params->t = 0.0;
}

void	draw_line_low(t_vars *vars, t_point *point1, t_point *point2)
{
	t_line_params	params;

	initialize_line_params_low(&params, point1, point2);
	while (params.j <= point2->j)
	{
		if (params.dj > params.di)
			params.t = calculate_t(params.j, point1->j, point2->j);
		else
			params.t = calculate_t(params.i, point1->i, point2->i);
		my_mlx_pixel_put(vars, params.i, params.j,
			interpolate_color(point1->color, point2->color, params.t));
		if (params.adjustment > 0)
		{
			params.i += params.increment;
			params.adjustment -= 2 * params.dj;
		}
		params.adjustment += 2 * params.di;
		params.j++;
	}
}

void	initialize_line_params_high(t_line_params *params, t_point *point1,
		t_point *point2)
{
	params->di = point2->i - point1->i;
	params->dj = point2->j - point1->j;
	params->increment = 1;
	if (params->dj < 0)
	{
		params->increment = -1;
		params->dj = -(params->dj);
	}
	params->adjustment = 2 * params->dj - params->di;
	params->i = point1->i;
	params->j = point1->j;
	params->t = 0.0;
}

void	draw_line_high(t_vars *vars, t_point *point1, t_point *point2)
{
	t_line_params	params;

	initialize_line_params_high(&params, point1, point2);
	while (params.i <= point2->i)
	{
		if (params.dj > params.di)
			params.t = calculate_t(params.j, point1->j, point2->j);
		else
			params.t = calculate_t(params.i, point1->i, point2->i);
		my_mlx_pixel_put(vars, params.i, params.j,
			interpolate_color(point1->color, point2->color, params.t));
		if (params.adjustment > 0)
		{
			params.j += params.increment;
			params.adjustment -= 2 * params.di;
		}
		params.adjustment += 2 * params.dj;
		params.i++;
	}
}

void	swap_points(t_point **point1, t_point **point2)
{
	t_point	*tmp;

	tmp = *point1;
	*point1 = *point2;
	*point2 = tmp;
}
