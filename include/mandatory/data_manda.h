/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manda.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:19:26 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/26 13:05:13 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DATA_MANDA_H
# define DATA_MANDA_H

# include "libft.h"
# include "lstmap.h"
# include "map.h"
# include "player.h"
# include "window.h"
# include "flood_fill.h"
# include "lstmap_extraction_manda.h"
# include "lstmap_extraction_utils_manda.h"
# include "textures_manda.h"
# include "key_move.h"
# include "ray.h"

# ifndef PI
#  define PI 3.14159265358979323846
#endif

#define FOV 90

typedef struct s_data
{
	void		*mlx;
	t_window	win;
	t_map		map;
	t_textures	textures;
	t_key		key;
	t_player	player;
	int			mouse_mode;
	t_ray_tab	rays;
	double		tg_fov_2;
}				t_data;

void	data_init(t_data *data);
int		mlx_setup(t_data *data, t_tex_path *tex_path, t_textures *textures);
int		data_setup(t_data *data, char *map_path);
void	data_clean(t_data *data);
void	tex_path_clean(t_tex_path *tex_path);

#endif
