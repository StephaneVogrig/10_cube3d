/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:21:52 by aska              #+#    #+#             */
/*   Updated: 2024/11/01 18:04:13 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

# include "lstmap_extraction_utils.h"
# include "map.h"
# include "player.h"
# include "stack.h"

int		map_checker(t_map *map, t_player *player);
char	**set_var_creation_map_ff(t_map *map);
t_bool	chk_flood_fill(t_map *map, int x, int y);

#endif