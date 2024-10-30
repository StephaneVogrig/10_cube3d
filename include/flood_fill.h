/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:21:52 by aska              #+#    #+#             */
/*   Updated: 2024/10/30 01:36:47 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

# include "file_process.h"
# include "map.h"
# include "player.h"
# include "stack.h"

int		map_checker(t_map *map, t_player *player);
char	**set_var_creation_map_ff(t_map *map);
void	chk_flood_fill(t_map *map, int x, int y, t_bool *ff_ok);

#endif