/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:40:28 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/19 21:40:46 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_isspace(int c)
{
	return (c && ft_strchr(" \f\n\r\t\v", c));
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (sign > 0 && n > (LONG_MAX - (str[i] - '0')) / 10)
			return ((int)LONG_MAX);
		if (sign < 0 && n > (LONG_MAX - (str[i] - '0')) / 10)
			return ((int)LONG_MIN);
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}
