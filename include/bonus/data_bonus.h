/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:19:26 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/04 16:51:30 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_BONUS_H
# define DATA_BONUS_H

# include "asset_bonus.h"
# include "asset_lst_bonus.h"
# include "door_bonus.h"
# include "flood_fill.h"
# include "interface_bonus.h"
# include "key_move.h"
# include "libft.h"
# include "lstmap.h"
# include "lstmap_extraction_bonus.h"
# include "map.h"
# include "mlx_setup_bonus.h"
# include "player.h"
# include "ray.h"
# include "sprite_bonus.h"
# include "sprite_lst_bonus.h"
# include "window.h"
# include <math.h>

# ifndef PI
#  define PI 3.14159265358979323846
# endif

# define FOV 90

typedef struct s_data_extract
{
	t_asset_lst		**asset_lst;
	t_sprite_lst	**sprite_lst;
}					t_data_extract;

typedef struct s_data
{
	void			*mlx;
	t_window		win;
	bool			win_focused;
	t_map			map;
	t_asset			textures;
	t_key			key;
	t_player		player;
	int				mouse_mode;
	bool			fog_enable;
	bool			collision_enable;
	bool			fps_enable;
	bool			in_wall;
	bool			in_door;
	bool			dark;
	t_ray_tab		rays;
	double			tg_fov_2;
	double			scale_screen;
	t_door_open		door_open_list[DOORS_SIZE];
	t_sprite		sprite;
	t_interface		minimap;
}					t_data;

void				data_init(t_data *data);
int					data_setup(t_data *data, char *map_path);
void				data_clean(t_data *data);

#endif
