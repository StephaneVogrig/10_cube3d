/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/23 19:51:59 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef EVENT_BONUS_H
# define EVENT_BONUS_H

# include "chrono.h"
# include "data_bonus.h"
# include "player_move_bonus.h"
# include "render_bonus.h"

# define KEY_ESC 41
# define KEY_W 26
# define KEY_A 4
# define KEY_S 22
# define KEY_D 7
# define KEY_T 23
# define KEY_LEFT 80
# define KEY_RIGHT 79

# define ON_DEMAND_CLOSE	0
# define ON_MOVE_WINDOW		1
# define ON_FLYOVER_START	4
# define ON_FLYOVER_END		6
# define ON_FOCUS_GAIN		5
# define ON_FOCUS_LOSS		7

void	event_setup(t_data *data);
int		on_keydown(int key, void *param);
int		on_keyup(int key, void *param);
int on_mousedown(int button, void *param);
int on_mouseup(int button, void *param);

#endif