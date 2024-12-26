/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:47:51 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/26 23:29:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef STRIP_H
# define STRIP_H

# include "limits.h"
# include "texture.h"

typedef struct s_strip
{
	t_texture	*img;
	int			screen_size;
	int			screen_start;
	int			screen_end;
	double		img_start;
	double		img_delta;
	int			dark;
}	t_strip;

int		strip_screen_size(int screen_scale, double distance);
void	strip_add_limit(t_strip *strip, int size);
void	strip_setup(t_strip *strip, int win_h);

#endif