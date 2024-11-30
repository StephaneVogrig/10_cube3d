/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:52:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/30 16:32:27 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DDA_H
# define DDA_H

# include "dda_utils.h"
# include "player.h"
# include "ray.h"
# include "map.h"

void	dda(t_ray *ray, t_map *map, t_position *start, int len_max);

#endif