/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_utils_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:51:50 by aska              #+#    #+#             */
/*   Updated: 2025/01/13 15:11:04 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_UTILS_BONUS_H
# define INTERFACE_UTILS_BONUS_H

# define MINIMAP_W 720
# define MINIMAP_H 480
# define TILES_W 24
# define TILES_H 24
# define PATH_ASSET_BG "assets/BG.png"
# define PATH_ASSET_FG "assets/FG.png"
# define PATH_ASSET_TILES "assets/tiles_minimap.png"

# include "window.h"
# include "texture.h"
# include "mlx.h"
# include "vector.h"
# include "map.h"

typedef struct s_tiles
{
	int 	*floor;
	int		*blank;
	int		*one_wall;
	int		*two_wall;
	int		*corner_wall;
	int		*three_wall;
	int		*four_wall;
	int		*one_corner;
	int		*two_corner;
	int		*three_corner;
	int		*four_corner;
	int		*one_wall_corner;
	int		*one_wall_two_corner;
	int		*two_wall_corner;
	int		*door;
	int		*door_one_wall;
	int		*door_two_wall;
	int		*empty;
}	t_tiles;

typedef struct s_interface{
	void		*win;
	void		*mlx;
	void		*img_fg;
	void		*img_map;
	void		*img_bg;
	int			scale;
	t_map		*map;
	t_player	*player;
	t_bool		visible;
	t_texture	fg;
	t_texture	bg;
	t_texture	tiles;
	t_tiles		tiles_index;
}   t_interface;

int interface_setup_texture(void *mlx, t_texture *tex, char *path);
void interface_tiles_buffer_index(t_tiles *tiles, t_texture *tex);
int increment_position(t_bool reset);

#endif