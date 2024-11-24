/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_mlx_img.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:38:15 by stephane          #+#    #+#             */
/*   Updated: 2024/11/15 02:56:58 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FLOOR_CEIL_MLX_IMG_H
# define FLOOR_CEIL_MLX_IMG_H

# include "mlx.h"
# include "window.h"
# include "color.h"

typedef struct s_floor_ceil
{
	void *normal;
	void *dark;
}	t_floor_ceil;

int		floor_ceil_init(t_window *win, int color_ceil, int color_floor);
void	floor_ceil_put_to_window(t_window *win, int dark);
void	floor_ceil_destroy(void *mlx);

#endif
