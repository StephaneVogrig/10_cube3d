/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:42:38 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/20 15:47:44 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "lst_map.h"
# include "map.h"
#include "libft.h"
#include "asset_bonus.h"
#include "texture.h"

void	map_print(t_map *map);
void	lstmap_print(t_lstmap *lstmap);
void	map_print_ptr(t_map *map);
void print_exit_code(int exit_code);
void print_texture(t_texture *t);

#endif