/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_table_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:11:25 by aska              #+#    #+#             */
/*   Updated: 2025/01/07 03:46:48 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pointer_table_bonus.h"

void	pointer_table_init_door(t_asset *asset, int i)
{
	if (asset->key[i][0] == 'R')
	{
		if (asset->key[i][1] == 'E')
			asset->door.r_edge = asset->value[i];
		else
			asset->door.right = asset->value[i];
	}
	else if (asset->key[i][0] == 'L')
	{
		if (asset->key[i][1] == 'E')
			asset->door.l_edge = asset->value[i];
		else
			asset->door.left = asset->value[i];
	}
	else if (asset->key[i][0] == 'T')
	{
		if (asset->key[i][1] == 'E')
			asset->door.t_edge = asset->value[i];
		else
			asset->door.twin = asset->value[i];
	}
}

void	pointer_table_init(t_asset *asset)
{
	int	i;

	i = -1;
	while (asset->key[++i] != NULL)
	{
		if (ft_strcmp(asset->key[i], "SP") == 0)
			continue ;
		if (asset->key[i][0] == 'W')
		{
			if (asset->key[i][1] == 'E')
				asset->nsew.west = asset->value[i];
			else
				asset->wall[asset->key[i][1] - WALL_OFFSET] = asset->value[i];
		}
		else if (asset->key[i][0] == 'F')
			asset->floor_ceil.floor = asset->value[i];
		else if (asset->key[i][0] == 'C')
			asset->floor_ceil.ceil = asset->value[i];
		else if (asset->key[i][0] == 'N')
			asset->nsew.north = asset->value[i];
		else if (asset->key[i][0] == 'S')
			asset->nsew.south = asset->value[i];
		else if (asset->key[i][0] == 'E')
			asset->nsew.east = asset->value[i];
		pointer_table_init_door(asset, i);
	}
}

t_texture	*ptr_tbl_get_orientation_wall(t_asset *asset, char orientation)
{
	if (asset->wall[0] != NULL)
		return (asset->wall[0]);
	if (orientation == 'N' && asset->nsew.north != NULL)
		return (asset->nsew.north);
	else if (orientation == 'S' && asset->nsew.south != NULL)
		return (asset->nsew.south);
	else if (orientation == 'E' && asset->nsew.east != NULL)
		return (asset->nsew.east);
	else if (orientation == 'W' && asset->nsew.west != NULL)
		return (asset->nsew.west);
	ft_display(ERROR, "ptr_tbl_get_orientation_wall: No texture found");
	return (NULL);
}

t_texture	*ptr_tbl_get_orientation_door(t_asset *asset, char cell,
		char orientation)
{
	if (orientation == 2 || orientation == 3)
	{
		if (cell == 'R' && asset->door.r_edge != NULL)
			return (asset->door.r_edge);
		else if (cell == 'L' && asset->door.l_edge != NULL)
			return (asset->door.l_edge);
		else if (cell == 'T' && asset->door.t_edge != NULL)
			return (asset->door.t_edge);
	}
	else
	{
		if (cell == 'R' && asset->door.right != NULL)
			return (asset->door.right);
		else if (cell == 'L' && asset->door.left != NULL)
			return (asset->door.left);
		else if (cell == 'T' && asset->door.twin != NULL)
			return (asset->door.twin);
	}
	ft_display(ERROR, "ptr_tbl_get_orientation_door: No texture found");
	return (NULL);
}

t_texture	*asset_get_texture_ptr(t_asset *t, char *cell, char orientation)
{
	if (*cell == '1')
		return (ptr_tbl_get_orientation_wall(t, orientation));
	else if (ft_isdigit(*cell) == TRUE)
		return (t->wall[*cell - WALL_OFFSET]);
	else if (*cell == 'R' || *cell == 'L' || *cell == 'T')
		return (ptr_tbl_get_orientation_door(t, *cell, orientation));
	else if (*cell == 'F')
		return (t->floor_ceil.floor);
	else if (*cell == 'C')
		return (t->floor_ceil.ceil);
	return (NULL);
}
