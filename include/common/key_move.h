/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:57:13 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/19 15:01:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef KEY_MOVE_H
# define KEY_MOVE_H

typedef unsigned char	t_ui8;

# define UP 0
# define DOWN 1

typedef union
{
	struct
	{
		t_ui8 w		: 1;
		t_ui8 a		: 1;
		t_ui8 s		: 1;
		t_ui8 d		: 1;
		t_ui8 left	: 1;
		t_ui8 right	: 1;
	};
	t_ui8				down;
}						t_key;

#endif