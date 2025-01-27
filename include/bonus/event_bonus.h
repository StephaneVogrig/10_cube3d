/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:27 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:08:21 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_BONUS_H
# define EVENT_BONUS_H

# include "data_bonus.h"
# include "game_loop_bonus.h"
# include "key_move.h"
# include "raycasting_bonus.h"

# define KEY_T 23

# define ON_DEMAND_CLOSE 0
# define ON_MOVE_WINDOW 1
# define ON_FLYOVER_START 4
# define ON_FLYOVER_END 6
# define ON_FOCUS_GAIN 5
# define ON_FOCUS_LOSS 7

void	event_setup(t_data *data);
int		on_keydown(int key, void *param);
int		on_keyup(int key, void *param);
int		on_mousedown(int button, void *param);
int		on_mouseup(int button, void *param);

#endif