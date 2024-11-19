/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_window_and_image.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:23:12 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 08:23:32 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_window_and_image(t_vars *vars)
{
	create_window(vars);
	allocate_image_data(vars);
	create_image(vars);
	get_image_data_address(vars);
}
