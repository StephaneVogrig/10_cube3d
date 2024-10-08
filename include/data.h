/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:19:26 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/08 02:50:55 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DATA_H
# define DATA_H

# include "../include/file_process.h"
# include "map.h"
# include "minimap_bonus.h"
# include "player.h"
# include "screen.h"
# include "texture.h"
# include "vec2i.h"
# include "window.h"
# include "flood_fill.h"

typedef unsigned int	t_ui32;
typedef unsigned char	t_ui8;

# define UP 0
# define DOWN 1

typedef union
{
	struct
	{
		t_ui8 w : 1;
		t_ui8 a : 1;
		t_ui8 s : 1;
		t_ui8 d : 1;
		t_ui8 left : 1;
		t_ui8 right : 1;
	};
	t_ui8				down;
}						t_key;

typedef struct s_data
{
	void				*mlx;
	t_window			win;
	t_map				map;
	t_key				key;
	t_player			player;
	t_minimap			minimap;
	int					minimap_scale;
	int					mouse_mode;
}						t_data;

void					data_init(t_data *data);
int						data_setup(t_data *data, char *pathname);
void					data_clean(t_data *data);

#endif
