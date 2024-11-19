/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:35:46 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 00:54:31 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int k)
{
	if (k < 2)
		return (0x1E90FF);
	else if (2 <= k && k < 4)
		return (0x00FF7F);
	else if (4 <= k && k < 6)
		return (0xFFD700);
	else
		return (0xFF4500);
}

int	interpolate_color(int color1, int color2, double t)
{
	int	red;
	int	green;
	int	blue;

	red = ((1 - t) * ((color1 >> 16) & 0xFF)) + (t * ((color2 >> 16) & 0xFF));
	green = ((1 - t) * ((color1 >> 8) & 0xFF)) + (t * ((color2 >> 8) & 0xFF));
	blue = ((1 - t) * (color1 & 0xFF)) + (t * (color2 & 0xFF));
	return ((red << 16) | (green << 8) | blue);
}
