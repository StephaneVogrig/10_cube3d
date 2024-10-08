/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:36:32 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/08 02:37:36 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "screen.h"

int	screen_init(t_screen *screen, void *mlx, int width, int height)
{
	screen->img = mlx_new_image(mlx, width, height);
	if (screen->img == NULL)
		return (ft_return(ERROR, FAIL, "Error screen init"));
	screen->mlx = mlx;
	screen->width = width;
	screen->height = height;
	return (chk_box(SUCCESS, EQ, SUCCESS, "Screen image initialization"));
}
