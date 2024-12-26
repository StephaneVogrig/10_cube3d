/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:13:53 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/26 13:47:10 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RAYCASTING_BONUS_H
# define RAYCASTING_BONUS_H

# include "map.h"
# include "player.h"
# include "ray.h"
# include "window.h"
# include "data_bonus.h"
# include "dda_bonus.h"
# include "door_bonus.h"

void	raycasting(t_ray *rays, t_data *data);

#endif
