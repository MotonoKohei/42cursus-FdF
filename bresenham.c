/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:32:54 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 08:53:24 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_image_line(t_vars *vars, t_point *point1, t_point *point2)
{
	if (ft_abs(point2->i - point1->i) < ft_abs(point2->j - point1->j))
	{
		if (point1->j > point2->j)
			swap_points(&point1, &point2);
		draw_line_low(vars, point1, point2);
	}
	else
	{
		if (point1->i > point2->i)
			swap_points(&point1, &point2);
		draw_line_high(vars, point1, point2);
	}
}

double	calculate_t(int current, int start, int end)
{
	double	ret;

	if (end == start)
		return (0.0);
	ret = (double)(current - start) / (end - start);
	return (ret);
}
