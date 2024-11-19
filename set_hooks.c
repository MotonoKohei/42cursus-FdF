/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:17:52 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 08:20:03 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_hooks(t_vars *vars)
{
	mlx_hook(vars->mlx_win, 4, 1L << 2, mouse_press, vars);
	mlx_hook(vars->mlx_win, 5, 1L << 3, mouse_release, vars);
	mlx_hook(vars->mlx_win, 6, 1L << 6, mouse_move, vars);
	mlx_key_hook(vars->mlx_win, key_press, vars);
}
