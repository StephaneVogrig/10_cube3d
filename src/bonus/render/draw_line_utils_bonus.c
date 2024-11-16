/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:57:15 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/16 17:51:08 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "draw_line_utils_bonus.h"

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

t_vec2i	increase(t_vec2i a, t_vec2i b)
{
	t_vec2i	i;
	
	if (a.x < b.x)
		i.x = 1;
	else
		i.x = -1;
	if (a.y < b.y)
		i.y = 1;
	else
		i.y = -1;
	return (i);
}
