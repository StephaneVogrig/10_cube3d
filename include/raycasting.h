/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:13:53 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/22 19:06:13 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "minimap_bonus.h"
# include "dda.h"
# include "draw_line.h"
# include "window.h"

void	raycasting(t_window *cub, t_minimap *minimap, t_map *map, t_player *player);

#endif