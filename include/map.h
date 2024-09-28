/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:55:14 by aska              #+#    #+#             */
/*   Updated: 2024/09/28 16:35:42 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "lst_map.h"

typedef struct
{
	char	**grid;
	int		width;
	int		height;
}			t_map;

int			init_map_process(t_map *map, t_lstmap **lst_map, int fd);
int			map_creation(t_map *map_t, t_lstmap **lst_map);
int			set_var_creation_map(t_map *map_t);
#endif