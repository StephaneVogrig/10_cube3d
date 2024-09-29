/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:47:16 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/29 02:21:40 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef WINDOW_H
# define WINDOW_H

# include <stddef.h>
# include <stdio.h>
# include "typedef.h"
# include "mlx.h"

# define WIN_W 1650
# define WIN_H 900

typedef struct s_window{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		focused;
}	t_window;

int		window_setup(t_window *win, void *mlx);
void	window_clean(t_window *win);

#endif