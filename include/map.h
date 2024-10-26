/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:31:37 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/26 16:41:52 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "file_process.h"
# include "lst_map.h"
# include "texture.h"
# include "typedef.h"
# include <stdio.h>
# include <stdlib.h>

# define AREA 'x'
# define WALL '1'

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	t_textures	textures;
}				t_map;

int				lstmap_extraction_info(void *mlx, t_lstmap **lst_map,
					t_map *map);
int				lstmap_to_grid(t_map *map, t_lstmap **lst_map);
int				map_creation(t_map *map_t, t_lstmap **lst_map);
int				set_var_creation_map(t_map *map_t);

#endif