/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manda.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/23 20:20:26 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef EVENT_MANDA_H
# define EVENT_MANDA_H

# include "data_manda.h"
# include "key_move.h"
# include "game_loop_manda.h"

# define ON_DEMAND_CLOSE 0

void	event_setup(t_data *data);
int		on_keydown(int key, void *param);
int		on_keyup(int key, void *param);

#endif