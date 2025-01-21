/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:19:26 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/21 11:56:01 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_BONUS_H
# define DATA_BONUS_H

# include <math.h>

# include "flood_fill.h"
# include "key_move.h"
# include "libft.h"
# include "lstmap.h"
# include "map.h"
# include "player.h"
# include "ray.h"
# include "window.h"

# include "asset_bonus.h"
# include "asset_lst_bonus.h"
# include "door_bonus.h"
# include "lstmap_extraction_bonus.h"
# include "interface_bonus.h"
# include "mlx_setup_bonus.h"
# include "sprite_bonus.h"
# include "sprite_lst_bonus.h"

# ifndef PI
#  define PI 3.14159265358979323846
#endif

#define FOV 90

typedef struct s_data
{
	void		*mlx;
	t_window	win;
	t_map		map;
	t_asset		textures;
	t_key		key;
	t_player	player;
	int			mouse_mode;
	int			fog_enable;
	int			dark;
	t_ray_tab	rays;
	double		tg_fov_2;
	double		scale_screen;
	t_door_open	door_open_list[DOORS_SIZE];
	t_sprite	sprite;
	t_interface	minimap;
}				t_data;

void	data_init(t_data *data);
int		data_setup(t_data *data, char *map_path);
void	data_clean(t_data *data);

#endif
