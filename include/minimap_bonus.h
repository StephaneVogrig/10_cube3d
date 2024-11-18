/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:14:09 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/16 20:20:37 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "map.h"
# include "mlx.h"
# include "vec2i.h"
# include "minimap_utils_bonus.h"
# include "data.h"

int		minimap_setup(void *mlx, t_map *map, t_data *data);
void	minimap_destroy(void);

#endif
