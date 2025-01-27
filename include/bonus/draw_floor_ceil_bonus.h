/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceil_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:56:00 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:05:34 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_FLOOR_CEIL_BONUS_H
# define DRAW_FLOOR_CEIL_BONUS_H

# include "color.h"
# include "data_bonus.h"
# include "fog_bonus.h"
# include "pointer_table_bonus.h"
# include "ray.h"

typedef struct s_element
{
	t_texture	*tex;
	int			y;
}				t_element;

typedef struct s_context
{
	int			dark;
	t_window	*win;
	t_vec2d		box;
	int			fog_enable;
	char		fog_tab[256];
}				t_context;

typedef struct s_floorceil_draw
{
	t_element	ceil;
	t_element	floor;
	t_context	context;
	t_vec2d		player_pos;
	int			winh_2;
	double		scalescreen_2;
	double		len;
}				t_floorceil_draw;

void			draw_floor_ceil(t_data *data);

#endif