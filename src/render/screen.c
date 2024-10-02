/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:36:32 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/27 16:34:14 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

int	screen_init(t_screen *screen, void *mlx, int width, int height)
{
	screen->img = mlx_new_image(mlx, width, height);
	if (screen->img == NULL)
		return (ERROR);
	screen->mlx = mlx;
	screen->width = width;
	screen->height = height;
	return (SUCCESS);
}
