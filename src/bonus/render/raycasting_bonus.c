/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/07 12:53:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "raycasting_bonus.h"

void	raycasting(t_map *map, t_player *player, t_ray *rays, t_door *door_open_list)
{
	t_vec2d	player_vdir;
	double	step_projection;
	t_vec2d	step_proj;
	t_vec2d projection;
	int		x;

	player_vdir.x = cos(player->dir);
	player_vdir.y = sin(player->dir);
	step_projection = 2.0 / WIN_W;
	step_proj.x = -player_vdir.y * step_projection;
	step_proj.y = player_vdir.x * step_projection;
	projection.x = player_vdir.x + player_vdir.y;
	projection.y = player_vdir.y - player_vdir.x;
	x = 0;
	while (x < WIN_W)
	{
		rays->vdir.x = projection.x;
		rays->vdir.y = projection.y;
		dda(rays, map, &player->position, door_open_list);
		projection.x += step_proj.x;
		projection.y += step_proj.y;
		rays++;
		x++;
	}
}
