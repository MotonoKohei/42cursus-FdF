/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:03:01 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 08:03:39 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_point(t_vars *vars, t_point *point)
{
	point->i -= (int)(vars->map->height / 2);
	point->i *= vars->scale;
	point->j -= (int)(vars->map->width / 2);
	point->j *= vars->scale;
	point->k *= vars->height_scale;
}

void	translate_point(t_vars *vars, t_point *point)
{
	point->i += vars->translate_i;
	point->j += vars->translate_j;
}
