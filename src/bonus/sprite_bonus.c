/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:55:38 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/21 06:44:30 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite_bonus.h"

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
		sprite->image[i] = textures->value[sprite_lst->id];
		sprite->anim_frame = sprite->image[i]->width / sprite->image[i]->height;
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
		if (sprite->transform[j].y < 0)
			break ;
		// printf("draw sprite %i | pos x: %f y:%f\n", j, sprite->pos[j].x, sprite->pos[j].y); //debug
		sprite_draw(sprite->image[j], sprite->transform[j], ray_tab, win);
		i++;
	}
}
