/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_table_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:11:25 by aska              #+#    #+#             */
/*   Updated: 2024/12/20 16:32:34 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pointer_table_bonus.h"

void pointer_table_init(t_asset *asset)
{
    int i = 0;

    printf("pointer_table_init\n");
    printf("asset->floor_ceil = %p", asset->floor_ceil);
    while (asset->key[i] != NULL)
    {
        printf("asset->key[%i] = %s\n", i,asset->key[i]);
        printf("asset->value[%i] = %p\n", i,asset->value[i]);
        if (asset->key[i][0] == 'W')
        {
            if (asset->key[i][1] - 48 != 1)
                asset->wall[asset->key[i][1] - 50] = asset->value[i];
        }
        else if (asset->key[i][0] == 'F')
            asset->floor_ceil->floor = asset->value[i];
        else if (asset->key[i][0] == 'C')
            asset->floor_ceil->ceil = asset->value[i];
        else if (asset->key[i][0] == 'R')
        {
            printf("asset->door->right = %p\n", asset->value[i]);
            asset->door->right = asset->value[i];
        }
        else if (asset->key[i][0] == 'L')
            asset->door->left = asset->value[i];
        else if (asset->key[i][0] == 'T')
            asset->door->twin = asset->value[i];
        else if (asset->key[i][0] == 'N')
            asset->nsew->north = asset->value[i];
        else if (asset->key[i][0] == 'S')
            asset->nsew->south = asset->value[i];
        else if (asset->key[i][0] == 'E')
            asset->nsew->east = asset->value[i];
        else if (asset->key[i][0] == 'W')
            asset->nsew->west = asset->value[i];
        i++;
    }
}

t_texture *ptr_tbl_get_orientation_wall(t_asset *asset, char orientation)
{
    if (orientation == 'N')
        return (asset->nsew->north);
    else if (orientation == 'S')
        return (asset->nsew->south);
    else if (orientation == 'E')
        return (asset->nsew->east);
    else if (orientation == 'W')
        return (asset->nsew->west);
    return (NULL);
}

t_texture	*asset_get_texture_ptr(t_asset *t, char *cell, char orientation)
{
    if (*cell == '1')
        return (ptr_tbl_get_orientation_wall(t, orientation));
    else if (ft_isdigit(*cell) == TRUE)
        return (t->wall[*cell - 50]);
    else if (*cell == 'F')
        return (t->floor_ceil->floor);
    else if (*cell == 'C')
        return (t->floor_ceil->ceil);
    else if (*cell == 'R')
        return (t->door->right);
    else if (*cell == 'L')
        return (t->door->left);
    else if (*cell == 'T')
        return (t->door->twin);
    return (NULL);
}
