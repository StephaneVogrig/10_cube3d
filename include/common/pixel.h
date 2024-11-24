/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:07:46 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/23 19:07:48 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PIXEL_H
# define PIXEL_H

typedef struct s_pixel{
	int	x;
	int	y;
	int	color;
}	t_pixel;

t_pixel	pixel(int x, int y, int color);

#endif