/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:47:16 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/05 15:26:06 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "libft.h"
# include "mlx.h"

/*
	assuming that the window size is even
*/
# define WIN_W 1280
# define WIN_H 768

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}			t_window;

int			window_setup(t_window *win, void *mlx);
void		window_destroy(t_window *win);
void		window_clear(t_window *win);
void		window_put_pixel(t_window *win, int x, int y, int color);
void		window_put_image(t_window *win, void *img, int x, int y);

#endif
