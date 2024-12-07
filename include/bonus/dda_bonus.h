/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:52:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/07 12:53:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DDA_H
# define DDA_H

# include "dda_utils.h"
# include "player.h"
# include "ray.h"
# include "map.h"
# include "door_bonus.h"

void	dda(t_ray *ray, t_map *map, t_position *start, t_door *door_open_list);

#endif