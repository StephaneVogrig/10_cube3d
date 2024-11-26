/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manda.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:19:26 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/26 15:34:56 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_MANDA_H
# define DATA_MANDA_H

# include "libft.h"
# include "lst_map.h"
# include "map.h"
# include "player.h"
# include "window.h"
# include "flood_fill.h"
# include "lstmap_extraction_manda.h"
# include "lstmap_extraction_utils_manda.h"
# include "textures_manda.h"

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
	void		*mlx;
	t_window	win;
	t_map		map;
	t_textures	textures;
	t_key		key;
	t_player	player;
	int			mouse_mode;
}				t_data;

void	data_init(t_data *data);
int		mlx_setup(t_data *data, t_tex_path *tex_path, t_textures *textures);
int		data_setup(t_data *data, char *map_path);
void	data_clean(t_data *data);
void	tex_path_clean(t_tex_path *tex_path);

#endif
