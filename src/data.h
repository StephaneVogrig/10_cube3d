/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:19:26 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/27 04:00:02 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DATA_H
# define DATA_H

# include "cub3d.h"
# include "screen.h"
# include "vec2i.h"
# include "map.h"

# define CUB_W 800
# define CUB_H 450
# define MINIMAP_W 800
# define MINIMAP_H 450

typedef unsigned int	t_ui32;

typedef struct s_vec2
{
	int					x;
	int					y;
}						t_vec2;

# define UP 0
# define DOWN 1

typedef union
{
	struct
	{
		char w : 1;
		char a : 1;
		char s : 1;
		char d : 1;
		char left : 1;
		char right : 1;
	};
	t_ui32				down;
}						t_key;

typedef struct s_player
{
	t_vec2i				pos;
	int					dir;
}						t_player;

typedef struct s_data
{
	void				*mlx;
	t_textures			textures;
	t_screen			cub;
	t_screen			minimap;
	t_map				map;
	t_key				key;
	t_player			player;

}						t_data;

void					data_init(t_data *data);
void					data_clean(t_data *data);

#endif