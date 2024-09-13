/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:47:57 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/12 20:19:56 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pixel.h"

t_pixel	pixel(int x, int y, int color)
{
	t_pixel	pix;

	pix.x = x;
	pix.y = y;
	pix.color = color;
	return (pix);
}
