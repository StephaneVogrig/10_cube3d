/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_minimap.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 02:47:14 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 16:04:08 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_IMG_MINIMAP_H
# define DRAW_IMG_MINIMAP_H

# include "interface_utils_bonus.h"

void	draw_image_minimap(t_interface *interface, t_vec2i start, t_vec2i end,
			t_map *map);

#endif