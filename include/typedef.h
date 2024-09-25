/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:42:41 by aska              #+#    #+#             */
/*   Updated: 2024/09/25 14:16:13 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef enum e_status
{
	FAIL = -1,
	SUCCESS = 0,
}					t_status;

typedef enum e_ref_path
{
	NO_REF,
	SO_REF,
	WE_REF,
	EA_REF,
	F_REF,
	C_REF,
	BGM_REF
}					t_ref_path;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_texture
{
	void			*img;
	char			*addr;
	int				img_w;
	int				img_h;
}					t_texture;

typedef struct s_textures
{
	t_texture		no;
	t_texture		so;
	t_texture		we;
	t_texture		ea;
	t_texture		floor;
	t_rgb			floor_rgb;
	t_texture		ceil;
	t_rgb			ceil_rgb;
}					t_textures;

typedef struct s_lstmap
{
	char			*line;
	struct s_lstmap	*next;
	struct s_lstmap	*prev;
}					t_lstmap;

typedef struct s_cub
{
	t_textures		textures;
	void			*mlx;
	int				err;
	int				fd;
	char			*root_path;
	char			*line;
	t_lstmap		*map;
	char			**map_tab;
	char			**map_ff;
	int				map_max_x;
	int				map_max_y;
	int				player_x;
	int				player_y;
	char			player_dir;
	int				player_dir_x;
	int				player_dir_y;
	int				player_plane_x;
	int				player_plane_y;
	int				player_speed;
	int				player_rot_speed;
	int				player_move_speed;
}					t_cub;

#endif