/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:13:53 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/23 18:40:40 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RAYCASTING_BONUS_H
# define RAYCASTING_BONUS_H

# include "map.h"
# include "player.h"
# include "ray.h"
# include "window.h"
# include "dda_bonus.h"
# include "door_bonus.h"

void	raycasting(t_map *map, t_player *player, t_ray_tab *rays,
					t_door *door_open_list);

#endif
