/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_utils_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:51:50 by aska              #+#    #+#             */
/*   Updated: 2025/02/04 23:53:39 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_UTILS_BONUS_H
# define INTERFACE_UTILS_BONUS_H

# define MINIMAP_W 540
# define MINIMAP_H 360
# define TILES_W 18
# define TILES_H 18
# define PATH_ASSET_BG "assets/BG.png"
# define PATH_ASSET_FG "assets/FG.png"
# define PATH_ASSET_TILES "assets/tiles_minimapV2.png"

# include "map.h"
# include "mlx.h"
# include "texture.h"
# include "vector.h"
# include "window.h"

typedef struct s_tiles_ptr
{
	int			*empty;
	int			*floor;
	int			*one;
	int			*two;
	int			*three;
	int			*four;
	int			*five;
	int			*six;
	int			*seven;
	int			*height;
	int			*nine;
	int			*twin;
	int			*left_door;
	int			*right_door;
}				t_tiles_ptr;

typedef struct s_interface
{
	void		*win;
	void		*mlx;
	void		*img_fg;
	void		*img_map;
	void		*img_bg;
	t_map		*map;
	t_player	*player;
	t_bool		visible;
	t_texture	fg;
	t_texture	bg;
	t_texture	tiles;
	t_tiles_ptr	tiles_index;
}				t_interface;

int				interface_setup_texture(void *mlx, t_texture *tex, char *path);
void			interface_tiles_buffer_index(t_tiles_ptr *tiles,
					t_texture *tex);

#endif