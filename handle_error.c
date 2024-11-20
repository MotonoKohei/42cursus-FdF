/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:01:41 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 12:00:03 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_error(const char *message)
{
	write(STDERR_FILENO, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}
