/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 02:44:03 by aska              #+#    #+#             */
/*   Updated: 2025/01/11 22:00:16 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_img_minimap.h"

static int chk_border(int x, int y, int width, int height)
{
    if (x < 0 || y < 0 || x >= width || y >= height)
        return (1);
    return (0);
}

static int chk_cell(char cell)
{
    if (ft_isthis(cell, "123456789"))
        return (1);
    else if (ft_isthis(cell, " "))
        return (2);
    return (0);
}

static int  *get_tile(char cell, t_tiles *tiles)
{
    if (chk_cell(cell) == 1)
    {
        return (tiles->blank);
    }
    else if (chk_cell(cell) == 2)
    {
        return (tiles->empty);
    }
    return (tiles->floor);
}   

static int   get_grid_position(int img_position, int tile_size)
{
    if (img_position <= 0)
        return (0);
    return (img_position / tile_size);
}

static void    draw_tile(t_interface *interface, t_vec2i pos, t_map *map)
{
    int x;
    int y;
    int *color;
    t_vec2i img_position;

    img_position.y = get_grid_position(pos.y, TILES_H);
    img_position.x = get_grid_position(pos.x, TILES_W);
    y = 0;
    color = get_tile(map->grid[img_position.y][img_position.x], &interface->tiles_index);
    while (y < TILES_H)
    {
        x = 0;
        while (x < TILES_W)
        {
            mlx_set_image_pixel(interface->mlx, interface->img_map, pos.x + x, pos.y + y, *color);
            x++;
        }
        y++;
    }
}

void    draw_image_minimap(t_interface *interface, t_vec2i start, t_vec2i end, t_map *map)
{
    t_vec2i         cursor;
    t_vec2i	        pos;

    cursor.y = start.y;

    while (cursor.y < end.y)
    {
        cursor.x = start.x;
        while (cursor.x < end.x)
        {
            printf("cursor.x: %d | cursor.y: %d\n", cursor.x, cursor.y);
            pos.y = cursor.y - start.y;
            pos.x = cursor.x - start.x;
            draw_tile(interface, pos, map);
            cursor.x += TILES_W;
        }
        cursor.y += TILES_H;
    }
}

