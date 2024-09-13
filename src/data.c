/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:18:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/13 03:14:47 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	data_init(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->player.pos.x = MINIMAP_W / 2;
	data->player.pos.y = MINIMAP_H / 2;
}

void	data_clean(t_data *data)
{
	printf("data_clean\n");
    
    if (data->cub.img)
	    mlx_destroy_image(data->mlx, data->cub.img);
    if (data->cub.win)
	    mlx_destroy_window(data->mlx, data->cub.win);
    if (data->minimap.img)
	    mlx_destroy_image(data->mlx, data->minimap.img);
    if (data->minimap.win)
	    mlx_destroy_window(data->mlx, data->minimap.win);
    if (data->mlx)
	    mlx_destroy_display(data->mlx);
}
