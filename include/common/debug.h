/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:42:38 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/23 18:41:51 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DEBUG_H
# define DEBUG_H

# include "lst_map.h"
# include "map_manda.h"
# include "textures_manda.h"

void	map_print(t_map *map);
void	lstmap_print(t_lstmap *lstmap);

#endif