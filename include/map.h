/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:31:37 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/23 22:00:29 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MAP_H
# define MAP_H

# include <stdio.h>
# include <stdlib.h>
# include "typedef.h"
# include "texture.h"

typedef struct s_map{
	char	**grid;
	int		width;
	int		height;
	t_textures	textures;
}	t_map;

int	map_setup(t_map *map);

#endif