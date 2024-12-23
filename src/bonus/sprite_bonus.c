/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:55:38 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/23 17:42:30 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "sprite_bonus.h"

static void	sprite_fill(t_sprite *sprite, t_sprite_lst *sprite_lst, t_asset *textures)
{
	int i;

	i = 0;
	while (sprite_lst != NULL)
	{
		sprite->image[i] = textures->value[sprite_lst->id];
		sprite->pos[i] = (t_vec2d){sprite_lst->x, sprite_lst->y};
		sprite->order[i] = i;
		sprite->nbr_state[i] = sprite->image[i]->width / sprite->image[i]->height;
		sprite_lst = sprite_lst->next;
		i++;
	}
}

int	sprite_setup(t_sprite *sprite, t_sprite_lst *sprite_lst, t_asset *textures)
{
	sprite->nbr = get_lst_size(sprite_lst);
	sprite->image = malloc(sprite->nbr * sizeof(*sprite->image));
	if (sprite->image == NULL)
		return (FAIL);
	sprite->pos = malloc(sprite->nbr * sizeof(*sprite->pos));
	if (sprite->pos == NULL)
		return (FAIL);
	sprite->transform = malloc(sprite->nbr * sizeof(*sprite->transform));
	if (sprite->transform == NULL)
		return (FAIL);
	sprite->order = malloc(sprite->nbr * sizeof(*sprite->order));
	if (sprite->order == NULL)
		return (FAIL);
	sprite->nbr_state = malloc(sprite->nbr * sizeof(*sprite->nbr_state));
	if (sprite->order == NULL)
		return (FAIL);
	sprite->state = ft_calloc(sprite->nbr, sizeof(*sprite->nbr_state));
	if (sprite->order == NULL)
		return (FAIL);
	sprite->collected = ft_calloc(sprite->nbr, sizeof(*sprite->collected));
	if (sprite->order == NULL)
		return (FAIL);
	sprite_fill(sprite, sprite_lst, textures);
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
	if (sprite->nbr_state)
		free(sprite->nbr_state);
	if (sprite->state)
		free(sprite->state);
	if (sprite->collected)
		free(sprite->collected);
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
	int	i;
	int	j;

	sprite_transform_coordonate(sprite, player);
	sprite_sort(sprite);
	sprite_collect(sprite, player);
	i = 0;
	while (i < sprite->nbr)
	{
		j = sprite->order[i];
		if (sprite->transform[j].y < 0)
			break ;
		if (sprite->collected[j] == FALSE)
			sprite_draw(sprite, j, win, ray_tab);
		i++;
	}
}
