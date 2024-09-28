/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:31:37 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/28 18:08:27 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "lst_map.h"
# include "texture.h"
# include "typedef.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	t_textures	textures;
}				t_map;

int				map_setup(t_map *map);
int				init_map_process(t_map *map, t_lstmap **lst_map, int fd);
int				map_creation(t_map *map_t, t_lstmap **lst_map);
int				set_var_creation_map(t_map *map_t);

#endif