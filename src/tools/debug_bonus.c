/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:12:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/19 22:18:30 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
