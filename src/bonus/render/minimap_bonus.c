/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:15:02 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/16 20:31:47 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minimap_bonus.h"
#include "window.h"
#include "event.h"

int	minimap_scale(t_map *map)
{
	t_vec2i	scale;

	scale.x = MINIMAP_W / map->width;
	scale.y = MINIMAP_H / map->height;
	if (scale.y < scale.x)
		return (scale.y);
	return (scale.x);
}

int window_hook(int event, void* mlx)
{
	if(event == 0)
		mlx_loop_end(mlx);
	return (SUCCESS);
}

void minimap_event_setup(t_minimap *minimap, t_data *data)
{
	mlx_on_event(minimap->mlx, minimap->win, MLX_MOUSEDOWN, on_mousedown, data);
	mlx_on_event(minimap->mlx, minimap->win, MLX_MOUSEUP, on_mouseup, data);
	mlx_on_event(minimap->mlx, minimap->win, MLX_KEYDOWN, on_keydown, data);
	mlx_on_event(minimap->mlx, minimap->win, MLX_KEYUP, on_keyup, data);
}

int	minimap_setup(void *mlx, t_map *map, t_data *data)
{
	t_minimap	*minimap;
	int			screen_w;
	int			screen_h;

	minimap = minimap_get_ptr();
	minimap->win = mlx_new_window(mlx, MINIMAP_W, MINIMAP_H, "minimap");
	if (minimap->win == NULL)
		return (ft_return(ERROR, FAIL, "Error: no new window in minimap setup"));
	minimap->img = mlx_new_image(mlx, MINIMAP_W, MINIMAP_H);
	if (minimap->img == NULL)
		return (ft_return(ERROR, FAIL, "Error: no new image in minimap setup"));
	mlx_get_screens_size(mlx, minimap->win, &screen_w, &screen_h);
	mlx_set_window_position(mlx, minimap->win, (screen_w + WIN_W) / 2, (screen_h - WIN_H) / 2);
	minimap->scale = minimap_scale(map);
	minimap->mlx = mlx;
	minimap_event_setup(minimap, data);
    mlx_on_event(mlx, minimap->win, MLX_WINDOW_EVENT, window_hook, mlx);
	return (chk_box(SUCCESS, EQ, SUCCESS, "Minimap setup"));
}

void	minimap_destroy(void)
{
	t_minimap	*minimap;
	
	minimap = minimap_get_ptr();
	if (minimap->img)
		mlx_destroy_image(minimap->mlx, minimap->img);
	if (minimap->win)
		mlx_destroy_window(minimap->mlx, minimap->win);
}
