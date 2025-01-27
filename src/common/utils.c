/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:30:48 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 15:49:42 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	choose_char(t_bool test, char val_if_true, char val_if_false)
{
	if (test == TRUE)
		return (val_if_true);
	return (val_if_false);
}

float	choose_float(t_bool test, float val_if_true, float val_if_false)
{
	if (test == TRUE)
		return (val_if_true);
	return (val_if_false);
}
