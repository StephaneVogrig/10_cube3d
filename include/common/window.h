/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:47:16 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 01:24:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef WINDOW_H
# define WINDOW_H

# include "libft.h"
# include "typedef.h"
# include "mlx.h"

# define WIN_W 1280
# define WIN_H 768

typedef struct s_window{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		focused;
}	t_window;

int		window_setup(t_window *win, void *mlx);
void	window_clean(t_window *win);
void	window_pixel_put(t_window *win, int x, int y, int color);

#endif