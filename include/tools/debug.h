/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:42:38 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/20 21:03:26 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DEBUG_H
# define DEBUG_H

# include "lst_map.h"
# include "map.h"
# include "libft.h"
# include "texture.h"

void	lstmap_print(t_lstmap *lstmap);
void	map_print(t_map *map);
void	map_print_ptr(t_map *map);
void	print_exit_code(int exit_code);
void	print_texture(t_texture *t);

#endif