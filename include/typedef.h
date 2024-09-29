/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:42:41 by aska              #+#    #+#             */
/*   Updated: 2024/09/29 11:03:45 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef enum e_status
{
	FAIL = -1,
	SUCCESS = 0,
}			t_status;

typedef enum e_ref_path
{
	NO_REF,
	SO_REF,
	WE_REF,
	EA_REF,
	F_REF,
	C_REF,
	BGM_REF
}			t_ref_path;

typedef union u_color
{
	struct
	{
		int	b : 8;
		int	g : 8;
		int	r : 8;
		int	a : 8;
	};
	int	integer;
}	t_rgb;

typedef struct s_cub
{
	void	*mlx;
	int		err;
	int		fd;
	char	*root_path;
	char	*line;
	int		player_x;
	int		player_y;
	char	player_dir;
	int		player_dir_x;
	int		player_dir_y;
	int		player_plane_x;
	int		player_plane_y;
	int		player_speed;
	int		player_rot_speed;
	int		player_move_speed;
}			t_cub;

#endif