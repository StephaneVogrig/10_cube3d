/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:13:08 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/02 20:52:29 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "libft.h"
# include "position.h"
# include "vector.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_ray
{
	t_vec2d		dirvec;
	double		len;
	int			wall_screen_height;
	t_position	hit_pos;
	char		*hit_cell;
	char		hit_axis;
	char		hit_side;
}				t_ray;

typedef struct s_ray_tab
{
	t_ray		*tab;
	int			nbr;
}				t_ray_tab;

int				ray_setup(t_ray_tab *rays, int nbr);
void			ray_destroy(t_ray_tab *rays);
t_vec2d			ray_vec_start(t_vec2d player_dirvec, double tg_fov_2);
t_vec2d			ray_vec_step(t_vec2d player_dirvec, int win_w, double tg_fov_2);

#endif
