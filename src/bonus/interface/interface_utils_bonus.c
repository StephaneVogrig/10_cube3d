/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:44:55 by aska              #+#    #+#             */
/*   Updated: 2025/01/24 03:05:50 by aska             ###   ########.fr       */
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

void interface_tiles_buffer_index(t_tiles_ptr *tiles, t_texture *tex)
{
	tiles->floor = &tex->buffer[increment_position(TRUE)];
	tiles->twin = &tex->buffer[increment_position(FALSE)];
	tiles->right_door = &tex->buffer[increment_position(FALSE)];
	tiles->left_door = &tex->buffer[increment_position(FALSE)];
	tiles->two = &tex->buffer[increment_position(FALSE)];
	tiles->three = &tex->buffer[increment_position(FALSE)];
	tiles->four = &tex->buffer[increment_position(FALSE)];
	tiles->five = &tex->buffer[increment_position(FALSE)];
	tiles->six = &tex->buffer[increment_position(FALSE)];
	tiles->seven = &tex->buffer[increment_position(FALSE)];
	tiles->height = &tex->buffer[increment_position(FALSE)];
	tiles->nine = &tex->buffer[increment_position(FALSE)];
	tiles->one = &tex->buffer[increment_position(FALSE)];
	tiles->empty = &tex->buffer[increment_position(FALSE)];
}
