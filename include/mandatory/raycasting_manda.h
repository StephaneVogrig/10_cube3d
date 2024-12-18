/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manda.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:13:53 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/18 23:49:48 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RAYCASTING_MANDA_H
# define RAYCASTING_MANDA_H

# include "map.h"
# include "player.h"
# include "ray.h"
# include "window.h"
# include "dda_manda.h"

void	raycasting(t_map *map, t_player *player, t_ray *rays);

#endif
