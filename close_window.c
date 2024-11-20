/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:23:07 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 12:13:51 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_vars *vars)
{
	if (vars->map)
		free_map(vars->map, vars->map->height);
	if (vars->img_data)
	{
		if (vars->img_data->img)
			mlx_destroy_image(vars->mlx, vars->img_data->img);
		free(vars->img_data);
	}
	if (vars->mlx_win)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}
