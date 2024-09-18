/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:18:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/18 09:33:35 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	data_init(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->key.down = 0;
}

void	data_clean(t_data *data)
{
	printf("data_clean\n");
    
    if (data->cub.win)
	    mlx_destroy_window(data->mlx, data->cub.win);
    if (data->minimap.screen.img)
	    mlx_destroy_image(data->mlx, data->minimap.screen.img);
    if (data->minimap.screen.win)
	    mlx_destroy_window(data->mlx, data->minimap.screen.win);
    if (data->mlx)
	    mlx_destroy_display(data->mlx);
}
