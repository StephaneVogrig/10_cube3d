/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:13:53 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/03 00:18:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_BONUS_H
# define RAYCASTING_BONUS_H

# include "cell_bonus.h"
# include "data_bonus.h"
# include "dda_bonus.h"
# include "door_bonus.h"
# include "player.h"
# include "position.h"
# include "ray.h"
# include "wall_screen_height.h"

void	raycasting(t_ray *rays, t_data *data);
void	raycast(t_ray *ray, t_position *start, t_data *data);

#endif
