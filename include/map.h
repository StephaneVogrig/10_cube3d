/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:31:37 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/30 12:06:14 by ygaiffie         ###   ########.fr       */
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
#include <limits.h>


# define AREA 'x'
# define WALL '1'

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	t_textures	textures;
}				t_map;

int				lstmap_extraction_info(t_lstmap **lst_map, t_map *map,
					char *path);
int				check_all_validity_line(t_map *map, t_lstmap **lst_map);
int				lstmap_to_grid(t_map *map_t, t_lstmap **lst_map);
int				set_var_creation_map(t_map *map_t);

#endif