/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_manda.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:47:51 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:04:54 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRIP_MANDA_H
# define STRIP_MANDA_H

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
}				t_strip;

int				strip_screen_size(int screen_scale, double distance);
void			strip_add_limit(t_strip *strip, int size);
void			strip_setup(t_strip *strip, int win_h);

#endif