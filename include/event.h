/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/25 17:20:08 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "chrono.h"
# include "render.h"
# include "player.h"

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

#endif