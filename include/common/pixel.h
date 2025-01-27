/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:07:46 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:04:40 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}		t_pixel;

t_pixel	pixel(int x, int y, int color);

#endif