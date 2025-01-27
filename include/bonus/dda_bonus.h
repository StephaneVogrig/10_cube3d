/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:52:20 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:04:05 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_BONUS_H
# define DDA_BONUS_H

# include "cell_bonus.h"
# include "data_bonus.h"
# include "dda_utils.h"
# include "door_bonus.h"
# include "door_collide_bonus.h"
# include "map.h"
# include "player.h"
# include "ray.h"

void	dda(t_ray *ray, t_position *start, t_data *data);

#endif