/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:36:49 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/17 20:59:34 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "../include/cub3d.h"
# include "vec2i.h"

typedef struct s_screen{
    void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;
	int	focused : 1;
	int	overfly : 1;
}   t_screen;

int	screen_init(t_screen *screen, void *mlx, int width, int height);

#endif