/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:55:38 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/02 14:15:57 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite_bonus.h"

static
void	sprite_fill(t_sprite *sprite, t_sprite_lst *sprite_lst,
		t_asset *textures)
{
	int	i;

	i = 0;
	while (sprite_lst != NULL)
	{
		sprite->image[i] = textures->value[sprite_lst->id];
		sprite->pos[i] = vector2d(sprite_lst->x, sprite_lst->y);
		sprite->order[i] = i;
		sprite->nbr_state[i] = sprite->image[i]->width
			/ sprite->image[i]->height;
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

static
bool	sprite_update_state(float *state, int nbr_state, t_time_us dt)
{
	int	state_start;

	if (nbr_state == 1)
		return (false);
	state_start = (int)*state;
	*state += SPRITE_CHANGE_PER_SECOND * (float)dt / USECOND_PER_SECOND;
	if (*state >= nbr_state)
		*state -= (nbr_state);
	if ((int)*state == state_start)
		return (false);
	return (true);
}

bool	sprite_update(t_sprite *sprite, t_time_us dt)
{
	bool	render_needed;
	int		i;

	render_needed = false;
	i = 0;
	while (i < sprite->nbr)
	{
		if (sprite->collected[i] == false)
			render_needed |= sprite_update_state(&sprite->state[i],
					sprite->nbr_state[i], dt);
		i++;
	}
	return (render_needed);
}
