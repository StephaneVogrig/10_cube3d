/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_minimap.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 02:47:14 by aska              #+#    #+#             */
/*   Updated: 2025/02/05 18:57:21 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_IMG_MINIMAP_H
# define DRAW_IMG_MINIMAP_H

# include "interface_utils_bonus.h"
# include "tile_rules.h"

void	draw_image_minimap(t_interface *interface, t_position *player_pos,
			t_map *map);

#endif