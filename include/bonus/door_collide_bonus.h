/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_collide_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:36:11 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:05:15 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_COLLIDE_BONUS_H
# define DOOR_COLLIDE_BONUS_H

# include "cell_bonus.h"
# include "data_bonus.h"
# include "door_bonus.h"

int	is_collide_door(t_ray *ray, t_position *start, t_data *data);

#endif
