/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:19:26 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/15 15:24:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "../include/cub3d.h"
# include "vec2i.h"
# include "screen.h"

# define CUB_W 800
# define CUB_H 450
# define MINIMAP_W 800
# define MINIMAP_H 450

typedef unsigned int 	t_ui32;
typedef unsigned char	t_ui8;

# define SPEED_ROT (M_PI / 400)
# define SPEED_MOVE 1


#define UP 0
#define DOWN 1


typedef union{
	struct {
		t_ui8	w : 1;
		t_ui8	a : 1;
		t_ui8	s : 1;
		t_ui8	d : 1;
		t_ui8	left : 1;
		t_ui8	right : 1;
	};
	t_ui8	down;
}	t_key;

typedef struct s_player{
	t_vec2d	pos;
	double	dir;
}	t_player;

typedef struct s_map{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_data{
	void		*mlx;
	t_screen	cub;
	t_screen	minimap;
	t_map		map;
	t_key		key;
	t_player	player;
}	t_data;

void	data_init(t_data *data);
void	data_clean(t_data *data);

#endif