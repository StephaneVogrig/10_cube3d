/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:12:27 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:36:22 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug_bonus.h"

void	print_exit_code(int exit_code)
{
	if (exit_code == SUCCESS)
		ft_printf("%i\t: " HGRN "SUCCESS\n" CRESET, exit_code);
	else if (exit_code == FAIL)
		ft_printf("%i\t: " HRED "FAIL\n" CRESET, exit_code);
	else
		ft_printf("%i\t: " HYEL "OTHER\n" CRESET, exit_code);
}

void	sprite_print(t_sprite *sprite)
{
	int		i;
	t_vec2d	*pos;
	t_vec2d	*transform;

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

void	print_buffer(t_texture *t)
{
	int	i;

	i = 0;
	while (i < t->height * t->width)
	{
		ft_printf("%i\t", i);
		ft_printf("%i\n", t->buffer[i]);
		i++;
	}
}

void	print_asset(t_asset *t)
{
	int	i;

	i = 0;
	printf("asset_tab...............................\n");
	while (t->key[i] != NULL)
	{
		ft_printf("key: %s\t|\t", t->key[i]);
		ft_printf("value: %p\n", t->value[i]);
		// print_buffer(t->value[i]);
		i++;
	}
	printf("asset_tab...............................end\n");
	printf("floor: %p\n", t->floor_ceil.floor);
	printf("ceil: %p\n", t->floor_ceil.ceil);
	printf("door.right: %p\n", t->door.right);
	printf("door.left: %p\n", t->door.left);
	printf("door.twin: %p\n", t->door.twin);
	printf("nswe.north: %p\n", t->nsew.north);
	printf("nswe.south: %p\n", t->nsew.south);
	printf("nswe.east: %p\n", t->nsew.east);
	printf("nswe.west: %p\n", t->nsew.west);
	i = 0;
	while (i < 9)
	{
		printf("wall[%i]: %p\n", i, t->wall[i]);
		i++;
	}
}

void	print_asset_lst(t_asset_lst *head)
{
	t_asset_lst *tmp;

	printf("asset_lst ++++++++++++++++++++++++\n");
	tmp = head;
	while (tmp != NULL)
	{
		printf("id: %d, key: %s, value: %s\n", tmp->id, tmp->key, tmp->value);
		tmp = tmp->next;
	}
	printf("asset_lst ++++++++++++++++++++++++ end\n");
}