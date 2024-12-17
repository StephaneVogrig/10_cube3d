/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manda.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/17 14:52:23 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef EVENT_MANDA_H
# define EVENT_MANDA_H

# include "data_manda.h"
# include "player_move_manda.h"
# include "render_manda.h"
# include "gametime.h"

# define KEY_ESC	41
# define KEY_W		26
# define KEY_A		4
# define KEY_S		22
# define KEY_D		7
# define KEY_LEFT	80
# define KEY_RIGHT	79

# define ON_DEMAND_CLOSE 0

void	event_setup(t_data *data);
int		on_keydown(int key, void *param);
int		on_keyup(int key, void *param);

#endif