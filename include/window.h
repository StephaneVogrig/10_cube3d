/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:47:16 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/22 19:30:35 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef WINDOW_H
# define WINDOW_H

# include <stddef.h>
# include <stdio.h>
# include "typedef.h"
# include "mlx.h"

# define WIN_W 1200
# define WIN_H 675

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