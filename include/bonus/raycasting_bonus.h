/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:13:53 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:04:22 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_BONUS_H
# define RAYCASTING_BONUS_H

# include "data_bonus.h"
# include "dda_bonus.h"
# include "door_bonus.h"
# include "map.h"
# include "player.h"
# include "ray.h"
# include "window.h"

void	raycasting(t_ray *rays, t_data *data);
void	raycast(t_ray *ray, t_position *start, t_data *data);

#endif
