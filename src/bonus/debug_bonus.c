/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:12:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/20 15:47:42 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug_bonus.h"

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

void	print_sprite_lst(t_sprite_lst *head)
{
	t_sprite_lst	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("id: %d, x: %f, y: %f\n", tmp->id, tmp->x, tmp->y);
		tmp = tmp->next;
	}
}

void print_buffer(t_texture *t)
{
	int i;

	i = 0;
	while (i < t->height * t->width)
	{
		ft_printf("%i\t", i);
		ft_printf("%i\n", t->buffer[i]);
		i++;
	}
}

void print_asset(t_asset *t)
{
	int i;

	i = 0;
	while (t->key[i] != NULL)
	{
		ft_printf("key: %s\t|\t", t->key[i]);
		ft_printf("value: %p\n", t->value[i]);
		// print_buffer(t->value[i]);
		i++;
	}
}