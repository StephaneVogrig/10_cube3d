/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:19:26 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/22 07:28:03 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_BONUS_H
# define DATA_BONUS_H

# include "file_load.h"
# include "flood_fill_bonus.h"
# include "libft.h"
# include "lst_map.h"
# include "lstmap_extraction_bonus.h"
# include "player.h"
# include "window.h"
# include "mlx_setup.h"

typedef unsigned int	t_ui32;
typedef unsigned char	t_ui8;

# define UP 0
# define DOWN 1

typedef union
{
	struct
	{
		t_ui8 w : 1;
		t_ui8 a : 1;
		t_ui8 s : 1;
		t_ui8 d : 1;
		t_ui8 left : 1;
		t_ui8 right : 1;
		t_ui8 esc : 1;
	};
	t_ui8				down;
}						t_key;

typedef struct s_data
{
	void				*mlx;
	t_window			win;
	t_map				map;
	t_key				key;
	t_player			player;
	int					mouse_mode;
}						t_data;

void					data_init(t_data *data);
int						data_setup(t_data *data, char *map_path);
void					data_clean(t_data *data);
#endif