/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:55:38 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/19 19:36:12 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite_bonus.h"
#include "sprite_lst_bonus.h"

static int get_lst_size(t_sprite_lst *head)
{
	int		size;
	t_sprite_lst	*tmp;

	size = 0;
	tmp = head;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

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

int	sprite_setup(t_sprite *sprite, t_sprite_lst *sprite_lst, t_asset *textures)
{
	int i;

	sprite->nbr = get_lst_size(sprite_lst);
	sprite->image = ft_calloc(sprite->nbr, sizeof(*sprite->image));
	if (sprite->image == NULL)
		return (FAIL);
	sprite->pos = ft_calloc(sprite->nbr, sizeof(*sprite->pos));
	if (sprite->pos == NULL)
		return (FAIL);
	sprite->transform = ft_calloc(sprite->nbr, sizeof(*sprite->transform));
	if (sprite->transform == NULL)
		return (FAIL);
	sprite->order = ft_calloc(sprite->nbr, sizeof(*sprite->order));
	if (sprite->order == NULL)
		return (FAIL);
	i = 0;
	while (sprite_lst != NULL)
	{
		sprite->pos[i] = (t_vec2d){sprite_lst->x, sprite_lst->y};
		sprite->image[i] = (t_texture *)&textures->value[sprite_lst->id];
		sprite->order[i] = i;
		sprite_lst = sprite_lst->next;
		i++;
	}
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
	new_coord.x = -(point.x * dir_vec.x + point.y * dir_vec.y);
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

void	sprite_draw(t_texture *texture, t_vec2d pos, t_ray *ray_tab, t_window *win)
{
	t_vec2i	screen;
	(void)texture;
	(void)ray_tab;
	(void)win;
	(void)screen;

	if (pos.y < 0)
		return;

	// printf("sprite_draw transform x: %f, transform y: %f\n", pos.x, pos.y); //debug

	screen.x = (WIN_W / 2) * (1 + (pos.x / pos.y));
	if (screen.x >=0 && screen.x < WIN_W && ray_tab[screen.x].len < pos.y)
		return ;
	int wall_h = WIN_H / pos.y;
	screen.y = (WIN_H - wall_h) / 2;

	// printf("sprite_draw screen x: %i y: %i wall_h: %i\n", screen.x, screen.y, wall_h); //debug
	int i = screen.y;
	while (i < screen.y + wall_h)
	{
		window_put_pixel(win, screen.x, i, 0xffff0000);
		i++;
	}
}

void	sprite_render(t_sprite *sprite, t_player *player, t_ray *ray_tab, t_window *win)
{
	(void)ray_tab;
	int	i;
	int	j;

	sprite_transform_coordonate(sprite, player);
	sprite_sort(sprite);
	i = 0;
	while (i < sprite->nbr)
	{
		j = sprite->order[i];
		// printf("draw sprite %i | pos x: %f y:%f\n", j, sprite->pos[j].x, sprite->pos[j].y); //debug
		sprite_draw(sprite->image[j], sprite->transform[j], ray_tab, win);
		i++;
	}
}
