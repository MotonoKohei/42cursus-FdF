/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:06:51 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/19 22:02:25 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_vars *vars, int i, int j, int color)
{
	char	*dst;

	if (i >= 0 && i < vars->win_height && j >= 0 && j < vars->win_width)
	{
		dst = vars->img_data->addr + (i * vars->img_data->line_length + j
				* vars->img_data->bits_per_pixel / 8);
		*(unsigned int *)dst = color;
	}
}
