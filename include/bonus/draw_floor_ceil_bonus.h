/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceil_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:56:00 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/23 19:05:10 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DRAW_FLOOR_CEIL_H
# define DRAW_FLOOR_CEIL_H

# include "data_bonus.h"
# include "pointer_table_bonus.h"
# include "ray.h"

void	draw_floor_ceil(t_data *data, t_ray *rays, int dark);

#endif