/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:53:00 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/25 19:24:05 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef union u_color
{
	struct
	{
		int	b : 8;
		int	g : 8;
		int	r : 8;
		int	a : 8;
	};
	int	integer;
}	t_rgb;

int color_darkened(int color, int dark);

#endif