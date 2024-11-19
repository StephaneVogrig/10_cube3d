/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:07:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/19 17:09:22 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_position	new_position(t_position start, double dir, t_vec2d move)
{
	double	cos_d;
	double	sin_d;
	t_vec2d	v;
	t_position new;
	
	cos_d = cos(dir);
	sin_d = sin(dir);
	v.x = move.x * cos_d - move.y * sin_d;
	v.y = move.x * sin_d + move.y * cos_d;
	new.x.box = start.x.box + v.x;
	new.y.box = start.y.box + v.y;
	new.x.grid = start.x.grid;
	new.y.grid = start.y.grid;
	player_adjust_position(&new.x.box, &new.x.grid);
	player_adjust_position(&new.y.box, &new.y.grid);
	return (new);
}

void	player_rotation(t_player *player, double rotation)
{
	player->dir += rotation;
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
