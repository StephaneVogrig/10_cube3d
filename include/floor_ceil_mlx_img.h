/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_mlx_img.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:38:15 by stephane          #+#    #+#             */
/*   Updated: 2024/11/06 01:41:54 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FLOOR_CEIL_MLX_IMG_H
# define FLOOR_CEIL_MLX_IMG_H

void	*floor_ceil_get_ptr_img(void);
void	*floor_ceil_get_ptr_img_dark(void);
int		floor_ceil_init(t_window *win, int color_ceil, int color_floor);
void	floor_ceil_destroy(void);

#endif