/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_point_3d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:10:44 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 01:40:21 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	rotate_point_3d(t_vars *vars, t_point *point)
// {
// 	t_point	rotated_point;
// 	double	angle_i;
// 	double	angle_j;

// 	angle_j = vars->angle_j;
// 	angle_i = vars->angle_i;
// 	rotated_point.j = (int)((point->j * cos(angle_i) + point->i * (sin(angle_j)
// 					* sin(angle_i)) + point->k * ((-1) * cos(angle_j)
// 					* sin(angle_i))));
// 	rotated_point.i = (int)((point->i * cos(angle_j) + point->k
// 				* sin(angle_j)));
// 	rotated_point.k = (int)(point->j * sin(angle_i) - point->i * sin(angle_j)
// 			* cos(angle_i) + point->k * cos(angle_j) * cos(angle_i));
// 	rotated_point.color = point->color;
// 	*point = rotated_point;
// }

void	rotate_point_3d(t_vars *vars, t_point *point)
{
	t_point	rotated_point;
	double	angle_i;
	double	angle_j;
	double	angle_k;

	angle_j = vars->angle_j;
	angle_i = vars->angle_i;
	angle_k = vars->angle_k;
	rotated_point.j = (int)((point->j * (cos(angle_i) * cos(angle_k)) + point->i
				* (sin(angle_j) * sin(angle_i) * cos(angle_k) + cos(angle_j)
					* sin(angle_k)) + point->k * ((-1) * cos(angle_j)
					* sin(angle_i) * cos(angle_k) + sin(angle_j)
					* sin(angle_k))));
	rotated_point.i = (int)((point->j * ((-1) * cos(angle_i) * sin(angle_k))
				+ point->i * (cos(angle_j) * cos(angle_k) - sin(angle_j)
					* sin(angle_i) * sin(angle_k)) + point->k * (sin(angle_j)
					* cos(angle_k) + cos(angle_j) * sin(angle_i)
					* sin(angle_k))));
	rotated_point.k = (int)(point->j * sin(angle_i) - point->i * sin(angle_j)
			* cos(angle_i) + point->k * cos(angle_j) * cos(angle_i));
	rotated_point.color = point->color;
	*point = rotated_point;
}
