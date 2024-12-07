/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:13:53 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/07 12:53:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RAYCASTING_BONUS_H
# define RAYCASTING_BONUS_H

# include "dda_bonus.h"
# include "door_bonus.h"
# include "window.h"

void	raycasting(t_map *map, t_player *player, t_ray *rays, t_door *door_open_list);

#endif
