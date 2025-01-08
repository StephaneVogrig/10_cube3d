/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:59:44 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/08 18:53:39 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "strip.h"

void	strip_add_limit(t_strip *strip, int size)
{
	strip->img_delta = (double)strip->img->height / strip->screen_size;
	if (strip->screen_start > 0
		&& (INT_MAX - strip->screen_start) < strip->screen_size)
		strip->screen_end = size;
	else
		strip->screen_end = strip->screen_start + strip->screen_size;
	if (strip->screen_start < 0)
	{
		strip->img_start += -strip->screen_start * strip->img_delta;
		strip->screen_start = 0;
	}
	if (strip->screen_end > size)
		strip->screen_end = size;
}

void	strip_setup(t_strip *strip, int win_h)
{
	strip->img_start = 0;
	strip->screen_start = (win_h - strip->screen_size) / 2;
	strip_add_limit(strip, win_h);
}
