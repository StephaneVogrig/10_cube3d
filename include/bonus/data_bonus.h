/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:19:26 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/23 19:27:47 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DATA_BONUS_H
# define DATA_BONUS_H

# include "asset_bonus.h"
# include "asset_lst_bonus.h"
# include "door_bonus.h"
# include "flood_fill.h"
# include "libft.h"
# include "lstmap.h"
# include "lstmap_extraction_bonus.h"
# include "map.h"
# include "mlx_setup_bonus.h"
# include "player.h"
# include "sprite_lst_bonus.h"
# include "window.h"
# include "mlx_setup_bonus.h"
# include "flood_fill.h"
# include "lstmap_extraction_bonus.h"
# include "asset_bonus.h"
# include "door_bonus.h"
# include "sprite_bonus.h"
# include "key_move.h"
# include "ray.h"

typedef struct s_data
{
	void		*mlx;
	t_window	win;
	t_map		map;
	t_asset		textures;
	t_key		key;
	t_player	player;
	int			mouse_mode;
	t_ray_tab	rays;
	t_door		door_open_list[DOORS_SIZE];
	t_sprite	sprite;
}				t_data;

void					data_init(t_data *data);
int						data_setup(t_data *data, char *map_path);
void					data_clean(t_data *data);

#endif
