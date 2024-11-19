/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_conical.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:25:00 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 07:05:59 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	convert_to_conical(t_vars *vars, t_point *point)
{
	int	viewpoint;

	viewpoint = (vars->map->height + vars->map->width) * vars->scale;
	point->j = point->j * viewpoint / (viewpoint - point->k);
	point->i = point->i * viewpoint / (viewpoint - point->k);
}
