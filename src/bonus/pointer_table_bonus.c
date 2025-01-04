/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_table_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:11:25 by aska              #+#    #+#             */
/*   Updated: 2024/12/31 03:44:21 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pointer_table_bonus.h"

void pointer_table_init(t_asset *asset)
{
    int i = -1;

    // mettre des ft_strcmp pour securiter des clef
    while (asset->key[++i] != NULL)
    {
        if (ft_strcmp(asset->key[i], "SP") == 0)
            continue;
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
        else if (asset->key[i][0] == 'R')
            asset->door.right = asset->value[i];
        else if (asset->key[i][0] == 'L')
            asset->door.left = asset->value[i];
        else if (asset->key[i][0] == 'T')
            asset->door.twin = asset->value[i];
        else if (asset->key[i][0] == 'N')
            asset->nsew.north = asset->value[i];
        else if (asset->key[i][0] == 'S')
            asset->nsew.south = asset->value[i];
        else if (asset->key[i][0] == 'E')
            asset->nsew.east = asset->value[i];
    }
}

t_texture *ptr_tbl_get_orientation_wall(t_asset *asset, char orientation)
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
    return (NULL);
}

t_texture	*asset_get_texture_ptr(t_asset *t, char *cell, char orientation)
{
    if (*cell == '1')
        return (ptr_tbl_get_orientation_wall(t, orientation));
    else if (ft_isdigit(*cell) == TRUE)
        return (t->wall[*cell - WALL_OFFSET]);
    else if (*cell == 'F')
        return (t->floor_ceil.floor);
    else if (*cell == 'C')
        return (t->floor_ceil.ceil);
    else if (*cell == 'R')
        return (t->door.right);
    else if (*cell == 'L')
        return (t->door.left);
    else if (*cell == 'T')
        return (t->door.twin);
    return (NULL);
}
