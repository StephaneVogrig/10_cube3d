/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:53:38 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/30 00:54:46 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	color_darkened(int color, int dark)
{
	if (dark)
		return ((color >> 2) & 0xFF3F3F3F);
	return (color);
}

int	color_set_rgb(t_rgb *rgb, char *value)
{
	char	**arg;

	arg = ft_split(value, ',');
	if (arg == NULL || ft_tablen(arg) != 3)
	{
		ft_tab_f(arg);
		return (ft_return(ERROR, FAIL, "malloc failed", "color_set_rgb"));
	}
	if (is_valid_color(arg[0]) == FALSE || is_valid_color(arg[1]) == FALSE
		|| is_valid_color(arg[2]) == FALSE)
	{
		ft_tab_f(arg);
		return (ft_return(ERROR, FAIL, "invalid color", value));
	}
	rgb->r = (unsigned char)ft_atoi(arg[0]);
	rgb->g = (unsigned char)ft_atoi(arg[1]);
	rgb->b = (unsigned char)ft_atoi(arg[2]);
	rgb->a = (unsigned char)255;
	ft_tab_f(arg);
	return (SUCCESS);
}
