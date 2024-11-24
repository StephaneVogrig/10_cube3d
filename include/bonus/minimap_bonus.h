/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:14:09 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/22 17:47:32 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "map_bonus.h"
# include "mlx.h"
# include "vec2i.h"
# include "minimap_utils_bonus.h"
# include "data_bonus.h"
#include "event_bonus.h"

int		minimap_setup(void *mlx, t_map *map, t_data *data);
void	minimap_destroy(void);

#endif
