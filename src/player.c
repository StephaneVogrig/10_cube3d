/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:07:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/05 18:42:26 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "player.h"

void	player_adjust_position(float *new_box, int *new_grid)
{
	if (*new_box >= 1.0)
	{
		*new_box -= 1.0;
		*new_grid += 1;
	}
	else if (*new_box < 0.0)
	{
		*new_box += 1.0;
		*new_grid -= 1;
	}
}

t_position	player_new_position(t_player *player, t_vec2i vec_dir)
{
	double	cos_d;
	double	sin_d;
	t_vec2d	v;
	t_position p;
	
	cos_d = cos(player->dir);
	sin_d = sin(player->dir);
	v.x = (vec_dir.x * cos_d - vec_dir.y * sin_d) * SPEED_MOVE;
	v.y = (vec_dir.x * sin_d + vec_dir.y * cos_d) * SPEED_MOVE;
	p.x.box = player->x.box + v.x;
	p.y.box = player->y.box + v.y;
	p.x.grid = player->x.grid;
	p.y.grid = player->y.grid;
	player_adjust_position(&p.x.box, &p.x.grid);
	player_adjust_position(&p.y.box, &p.y.grid);
	return (p);
}

void	player_rotation(t_player *player, int rot)
{
	player->dir += rot * SPEED_ROT;
	if (player->dir > M_PI)
		player->dir = player->dir - 2 * M_PI;
	if (player->dir < -M_PI)
		player->dir = player->dir + 2 * M_PI;
}

void	player_set_dir(t_player *player, char dir)
{
	if (dir == 'N')
		player->dir = -M_PI_2;
	else if (dir == 'S')
		player->dir = M_PI_2;
	else if (dir == 'W')
		player->dir = M_PI;
	else if (dir == 'E')
		player->dir = 0;
}

int	player_finder(t_map *map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (map->grid[++y] != NULL)
	{
		x = 0;
		while (map->grid[y][x] != 0)
		{
			if (ft_isthis(map->grid[y][x], "NSWE"))
			{
				player_set_dir(player, map->grid[y][x]);
				player->x.grid = x;
				player->y.grid = y;
				player->x.box = 0.5;
				player->y.box = 0.5;
			}
			x++;
		}
	}
	if (player->x.grid == 0 && player->y.grid == 0)
		return (ft_return(ERROR, FAIL, "No player on map"));
	return (SUCCESS);
}
