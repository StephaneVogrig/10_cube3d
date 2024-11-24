/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:37:08 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 06:01:22 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MINIMAP_UTILS_BONUS_H
# define MINIMAP_UTILS_BONUS_H

# include "map.h"
# include "player.h"

# define MINIMAP_W 320
# define MINIMAP_H 180

typedef struct s_minimap{
	void		*mlx;
	void		*win;
	void		*img;
	int			scale;
	t_map		*map;
	t_player	*player;
}   t_minimap;

t_minimap	*minimap_get_ptr(void);

#endif