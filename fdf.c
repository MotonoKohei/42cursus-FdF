/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:28:22 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 08:20:58 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_map	map;

	validate_input(argc);
	initialize_mlx(&vars);
	initialize_vars(&vars, &map, argv[1]);
	initialize_window_and_image(&vars);
	draw_image(&vars);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img_data->img, 0, 0);
	set_hooks(&vars);
	mlx_loop(vars.mlx);
}

void	init_point(t_point *point, int i, int j, int k)
{
	point->i = i;
	point->j = j;
	point->k = k;
	point->color = get_color(k);
}
