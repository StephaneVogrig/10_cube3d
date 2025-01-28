/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_open_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 01:15:21 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/28 15:28:50 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_OPEN_BONUS_H
# define DOOR_OPEN_BONUS_H

# include "map.h"
# include "door_bonus.h"
# include "data_bonus.h"

void	open_door_auto(t_map *map, int x, int y, t_door_open *door_open_list);
void	open_door_auto_near_player(t_data *data, t_map *map,
			t_door_open *door_open_list);

#endif