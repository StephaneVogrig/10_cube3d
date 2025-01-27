/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_mlx_img.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:38:15 by stephane          #+#    #+#             */
/*   Updated: 2025/01/27 16:04:34 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_CEIL_MLX_IMG_H
# define FLOOR_CEIL_MLX_IMG_H

# include "color.h"
# include "mlx.h"
# include "window.h"

typedef struct s_floor_ceil
{
	void	*normal;
	void	*dark;
}			t_floor_ceil;

int			floor_ceil_init(t_window *win, int color_ceil, int color_floor);
void		floor_ceil_put_to_window(t_window *win, int dark);
void		floor_ceil_destroy(void *mlx);

#endif
