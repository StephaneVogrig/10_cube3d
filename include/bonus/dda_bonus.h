/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:52:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/31 15:38:38 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DDA_BONUS_H
# define DDA_BONUS_H

# include "dda_utils.h"
# include "player.h"
# include "ray.h"
# include "map.h"
# include "data_bonus.h"
# include "door_bonus.h"
# include "door_collide_bonus.h"
# include "cell_bonus.h"

void	dda(t_ray *ray, t_position *start, t_data *data);

#endif