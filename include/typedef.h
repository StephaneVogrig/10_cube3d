/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:42:41 by aska              #+#    #+#             */
/*   Updated: 2024/09/10 16:26:29 by aska             ###   ########.fr       */
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
typedef struct s_img
{
	int				path_ok;
	int				img_w;
	int				img_h;
	void			*no;
	char			*no_path;
	void			*so;
	char			*so_path;
	void			*we;
	char			*we_path;
	void			*ea;
	char			*ea_path;
	t_rgb			f_rgb;
	void			*f;
	char			*f_path;
	t_rgb			c_rgb;
	void			*c;
	char			*c_path;
	char			*bgm_path;
}					t_img;

typedef struct s_win
{
	void			*w_game;
	int				game_wid;
	int				game_hei;
	void			*w_mini;
	int				mini_wid;
	int				mini_hei;
}					t_win;

typedef struct s_lstmap
{
	char			*line;
	struct s_lstmap	*next;
	struct s_lstmap	*prev;
}					t_lstmap;

typedef struct s_cub
{
	t_img			*img;
	void			*mlx;
	t_win			*win;
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