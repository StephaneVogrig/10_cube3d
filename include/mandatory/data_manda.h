/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manda.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:19:26 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/03 22:24:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_MANDA_H
# define DATA_MANDA_H

# include "flood_fill.h"
# include "floor_ceil_mlx_img_manda.h"
# include "key_move.h"
# include "libft.h"
# include "lstmap.h"
# include "lstmap_extraction_manda.h"
# include "map.h"
# include "player.h"
# include "ray.h"
# include "textures_manda.h"
# include "window.h"

# ifndef PI
#  define PI 3.14159265358979323846
# endif

# define FOV 90

typedef struct s_data
{
	void			*mlx;
	t_window		win;
	t_map			map;
	t_textures		textures;
	t_key			key;
	t_player		player;
	int				mouse_mode;
	int				fps_enable;
	int				dark;
	t_ray_tab		rays;
	double			tg_fov_2;
	double			scale_screen;
	t_floor_ceil	floorceil_imgs;
}				t_data;

void			data_init(t_data *data);
int				mlx_setup(t_data *data, t_tex_path *tex_path,
					t_textures *textures);
int				data_setup(t_data *data, char *map_path);
void			data_clean(t_data *data);

#endif
