/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:44:55 by aska              #+#    #+#             */
/*   Updated: 2025/01/11 13:25:31 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface_utils_bonus.h"

int interface_setup_texture(void *mlx, t_texture *tex, char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == FAIL)
		return (ft_return(ERROR, FAIL, "interface_setup_texture: no open asset"));
	close(fd);
	if (texture_load_to_buffer(mlx, tex, path) == FAIL)
		return (ft_return(ERROR, FAIL, "interface_setup_texture: load texture error"));
	return (SUCCESS);
}

int increment_position(t_bool reset)
{
	static int position = 0;

	if (reset)
	{
		position = 0;
		return (position);
	}
	return (position += TILES_W * TILES_H);
}

void interface_tiles_buffer_index(t_tiles *tiles, t_texture *tex)
{
	tiles->floor = &tex->buffer[increment_position(TRUE)];
	tiles->blank = &tex->buffer[increment_position(FALSE)];
	tiles->one_wall = &tex->buffer[increment_position(FALSE)];
	tiles->two_wall = &tex->buffer[increment_position(FALSE)];
	tiles->corner_wall = &tex->buffer[increment_position(FALSE)];
	tiles->three_wall = &tex->buffer[increment_position(FALSE)];
	tiles->four_wall = &tex->buffer[increment_position(FALSE)];
	tiles->one_corner = &tex->buffer[increment_position(FALSE)];
	tiles->two_corner = &tex->buffer[increment_position(FALSE)];
	tiles->three_corner = &tex->buffer[increment_position(FALSE)];
	tiles->four_corner = &tex->buffer[increment_position(FALSE)];
	tiles->one_wall_corner = &tex->buffer[increment_position(FALSE)];
	tiles->one_wall_two_corner = &tex->buffer[increment_position(FALSE)];
	tiles->two_wall_corner = &tex->buffer[increment_position(FALSE)];
	tiles->door = &tex->buffer[increment_position(FALSE)];
	tiles->door_one_wall = &tex->buffer[increment_position(FALSE)];
	tiles->door_two_wall = &tex->buffer[increment_position(FALSE)];
	tiles->empty = &tex->buffer[increment_position(FALSE)];
}
