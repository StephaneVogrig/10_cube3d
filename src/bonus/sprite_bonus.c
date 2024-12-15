/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:55:38 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/15 15:24:18 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "sprite_bonus.h"

void	sprite_print(t_sprite *sprite)
{
	int	i;
	t_vec2d	*pos;
	t_vec2d *transform;

	printf("-----------sprites-------------\nnbr: %i\n", sprite->nbr);
	pos = sprite->pos;
	transform = sprite->transform;
	i = 0;
	while (i < sprite->nbr)
	{
		printf("sprite %i | ", i);
		printf("pos x: %f y:%f | ", (*pos).x, (*pos).y);
		printf("transform x: %f y:%f\n", (*transform).x, (*transform).y);
		pos++;
		transform++;
		i++;
	}
	i = 0;
	while (i < sprite->nbr)
	{
		printf("order[%i] = %i\n", i, sprite->order[i]);
		i++;
	}
	printf("-------------------------------\n");
}

int	sprite_setup(t_sprite *sprite)
{
	printf("sprite_setup\n");

	sprite->nbr = 3;
	sprite->image = ft_calloc(sprite->nbr, sizeof(*sprite->image));
	if (sprite->image == NULL)
		return (FAIL);
	sprite->pos = calloc(sprite->nbr, sizeof(*sprite->pos));
	if (sprite->pos == NULL)
		return (FAIL);
	sprite->transform = ft_calloc(sprite->nbr, sizeof(*sprite->transform));
	if (sprite->transform == NULL)
		return (FAIL);
	sprite->order = ft_calloc(sprite->nbr, sizeof(*sprite->order));
	if (sprite->order == NULL)
		return (FAIL);
	sprite->pos[0] = (t_vec2d){2.0, 2.0};
	sprite->pos[1] = (t_vec2d){6.5, 2.5};
	sprite->pos[2] = (t_vec2d){3.5, 4.5};
	sprite->order[0] = 0;
	sprite->order[1] = 1;
	sprite->order[2] = 2;
	return (SUCCESS);
}

void	sprite_destroy(t_sprite *sprite)
{
	printf("sprite_destroy\n");
	
	if (sprite->image)
		free(sprite->image);
	if (sprite->pos)
		free(sprite->pos);
	if (sprite->transform)
		free(sprite->transform);
	if (sprite->order)
		free(sprite->order);
}

t_vec2d	coord_transform_translate(t_vec2d point, t_vec2d new_origin)
{
	t_vec2d	new_coord;

	new_coord.x = point.x - new_origin.x;
	new_coord.y = point.y - new_origin.y;
	return (new_coord);
}

t_vec2d	coord_transform_rotate(t_vec2d point, double dir)
{
	t_vec2d	new_coord;
	t_vec2d	dir_vec;

	dir_vec = dir_to_dirvec(dir);
	new_coord.x = point.x * dir_vec.x + point.y * dir_vec.y;
	new_coord.y = -point.x * dir_vec.y + point.y * dir_vec.x;
	return (new_coord);
}

void	sprite_transform_coordonate(t_sprite *sprite, t_player *player)
{
	t_vec2d	player_pos;
	t_vec2d	*sprite_pos;
	t_vec2d	*transform;
	double	dir_rot;
	int		i;

	player_pos.x = player->x.grid + player->x.box;
	player_pos.y = player->y.grid + player->y.box;
	sprite_pos = sprite->pos;
	transform = sprite->transform;
	dir_rot = player->dir - M_PI_2;
	i = 0;
	while (i < sprite->nbr)
	{
		*transform = coord_transform_translate(*sprite_pos, player_pos);
		*transform = coord_transform_rotate(*transform, dir_rot);
		sprite_pos++;
		transform++;
		i++;
	}
}

void	sprite_sort(t_sprite *sprite)
{
	int	i;
	int	j;
	int	sorting;

	i = 1;
	while (i < sprite->nbr)
	{
		sorting = sprite->order[i];
		j = i;
		while (j > 0 && sprite->transform[sorting].y > sprite->transform[sprite->order[j - 1]].y)
		{
			sprite->order[j] = sprite->order[j - 1];
			j--;
		}
		sprite->order[j] = sorting;
		i++;
	}
}

void	sprite_render(t_sprite *sprite, t_player *player, t_ray *ray_tab)
{
	(void)ray_tab;

	sprite_transform_coordonate(sprite, player);
	sprite_sort(sprite);
}
