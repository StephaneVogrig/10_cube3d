/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:27:09 by aska              #+#    #+#             */
/*   Updated: 2024/11/25 19:26:33 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_BONUS_H
# define ASSET_BONUS_H

# include "asset_lst_bonus.h"
# include "color.h"
# include "libft.h"
# include "texture.h"

# define NBR_KEY_IN_GRID 13
# define NBR_WALLKEY_IN_GRID 9

typedef struct s_nsew
{
	t_texture		*north;
	t_texture		*south;
	t_texture		*east;
	t_texture		*west;
}					t_nsew;

typedef struct s_door_tex
{
	t_texture		*right;
	t_texture		*r_edge;
	t_texture		*left;
	t_texture		*l_edge;
	t_texture		*twin;
	t_texture		*t_edge;
}					t_door_tex;

typedef struct s_floor_ceil
{
	t_texture		*floor;
	t_texture		*ceil;
}					t_floor_ceil;

typedef struct s_asset
{
	char			**key;
	t_texture		**value;
	t_floor_ceil	floor_ceil;
	t_door_tex		door;
	t_nsew			nsew;
	t_texture		*wall[NBR_WALLKEY_IN_GRID];
}					t_asset;

/*
	the array wall is adressed by char from '1' to '9'
	so we use '1' = 49 as offset
 */
# define WALL_OFFSET 49

int					asset_lst_to_array(void *mlx, t_asset *textures,
						t_asset_lst *head);
int					asset_destroy(t_asset *t);
void				print_asset_array(t_asset *t);

#endif
