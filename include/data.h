/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:19:26 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/01 19:18:42 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "lstmap_extraction_utils.h"
# include "lstmap_extraction.h"
# include "flood_fill.h"
# include "libft.h"
# include "lst_map.h"
# include "map.h"
# include "minimap_bonus.h"
# include "player.h"
# include "window.h"
# include "file_load.h"

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
		t_ui8 esc : 1;
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
int						mlx_setup(t_data *data);
int						data_setup(t_data *data, char *map_path);
void					data_clean(t_data *data);

#endif
