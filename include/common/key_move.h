/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:57:13 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/03 22:23:45 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MOVE_H
# define KEY_MOVE_H

# include "vector.h"

typedef unsigned char	t_ui8;

# define KEY_ESC 41

# define KEY_P 19

# define KEY_W 26
# define KEY_A 4
# define KEY_S 22
# define KEY_D 7
# define KEY_LEFT 80
# define KEY_RIGHT 79

# define UP 0
# define DOWN 1

typedef union s_key_push
{
	struct
	{
		t_ui8	w : 1;
		t_ui8	a : 1;
		t_ui8	s : 1;
		t_ui8	d : 1;
		t_ui8	left : 1;
		t_ui8	right : 1;
	};
	t_ui8				down;
}						t_key;

t_vec2i					key_to_move(t_key key);
int						is_moving(t_vec2i move);
void					set_key_up(t_key *key, int key_pressed);
void					set_key_down(t_key *key, int key_pressed);

#endif