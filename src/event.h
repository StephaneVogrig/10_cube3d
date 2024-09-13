/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/13 03:31:14 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "render.h"

# define KEY_ESC 41
# define KEY_W 26
# define KEY_A 4
# define KEY_S 22
# define KEY_D 7
# define KEY_LEFT 80
# define KEY_RIGHT 79
// # define KEY_ARROW_UP 65362
// # define KEY_ARROW_DOWN 65364
// # define KEY_PGUP 65365
// # define KEY_PGDOWN 65366
// # define KEY_SPACE 32

// # define KEY_F1 65470
// # define KEY_F2 65471
// # define KEY_F3 65472
// # define KEY_F4 65473
// # define KEY_F5 65474
// # define KEY_F6 65475
// # define KEY_F7 65476

// # define NUMPAD_KEY_4 65430
// # define NUMPAD_KEY_8 65431
// # define NUMPAD_KEY_6 65432
// # define NUMPAD_KEY_2 65433
// # define NUMPAD_KEY_5 65437
// # define NUMPAD_KEY_MORE 65451
// # define NUMPAD_KEY_MINUS 65453
// # define NUMPAD_KEY_ENTER 65421
// # define NUMPAD_KEY_SLASH 65455


void	event_setup(t_data *data);

#endif