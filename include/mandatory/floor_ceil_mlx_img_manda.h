/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_mlx_img_manda.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:38:15 by stephane          #+#    #+#             */
/*   Updated: 2025/02/03 18:39:07 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_CEIL_MLX_IMG__MANDA_H
# define FLOOR_CEIL_MLX_IMG__MANDA_H

# include "color.h"
# include "mlx.h"
# include "window.h"

typedef struct s_floor_ceil
{
	void	*normal;
	void	*dark;
}			t_floor_ceil;

int			floor_ceil_init(t_window *win, int color_ceil, int color_floor,
							t_floor_ceil *mlx_imgs);
void		floor_ceil_put_to_window(t_window *win, int dark,
										t_floor_ceil *mlx_imgs);
void		floor_ceil_destroy(void *mlx, t_floor_ceil *mlx_imgs);

#endif
