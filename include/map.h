/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:31:37 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/24 00:36:23 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

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

int				map_setup(void *mlx, t_lstmap **lst_map, t_map *map);
int				init_map_process(t_map *map, t_lstmap **lst_map);
int				map_creation(t_map *map_t, t_lstmap **lst_map);
int				set_var_creation_map(t_map *map_t);

#endif