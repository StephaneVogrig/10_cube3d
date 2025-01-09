/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:53:00 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/09 01:14:09 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef COLOR_H
# define COLOR_H

#include "check_arg.h"
#include "libft.h"

typedef union u_color
{
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
	int	integer;
}	t_rgb;

int color_darkened(int color, int dark);
int	color_set_rgb(t_rgb *rgb, char *value);

#endif