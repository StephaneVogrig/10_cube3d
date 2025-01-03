/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_collide_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:36:11 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/01 15:21:24 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DOOR_COLLIDE_BONNUS_H
# define DOOR_COLLIDE_BONNUS_H

#include "door_bonus.h"
#include "data_bonus.h"
#include "cell_bonus.h"

int		is_collide_door(t_ray *ray, t_position *start, t_data *data);

#endif
