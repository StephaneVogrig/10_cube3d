/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:14:09 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/28 14:32:44 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "map.h"
# include "mlx.h"
# include "player.h"
# include "vector.h"
# include "window.h"

# define MINIMAP_W 320
# define MINIMAP_H 180

typedef struct s_minimap{
	void		*mlx;
	void		*win;
	void		*img;
	int			scale;
	t_map		*map;
	t_player	*player;
	t_bool		visible;
}   t_minimap;

int		minimap_setup(t_minimap	*minimap, void *mlx, t_window *win, t_map *map);
void	minimap_destroy(t_minimap *minimap);

#endif
