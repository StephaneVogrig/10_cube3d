/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:42:38 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:18:30 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "libft.h"
# include "lstmap.h"
# include "map.h"
# include "texture.h"

void	lstmap_print(t_lstmap *lstmap);
void	map_print(t_map *map);
void	map_print_ptr(t_map *map);
void	print_exit_code(int exit_code);
void	print_texture(t_texture *t);

#endif