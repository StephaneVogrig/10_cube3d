/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:42:38 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/01 19:15:05 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "lst_map.h"
# include "map.h"
# include "texture.h"

void	map_print(t_map *map);
void	lstmap_print(t_lstmap *lstmap);
void	textures_print_ptr(t_textures *textures);

#endif