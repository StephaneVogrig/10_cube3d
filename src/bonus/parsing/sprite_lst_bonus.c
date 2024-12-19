/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_lst_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:44:20 by aska              #+#    #+#             */
/*   Updated: 2024/12/19 22:25:42 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "sprite_lst_bonus.h"

t_sprite_lst	*insert_sprite_lst(t_sprite_lst **head, double x, double y,
		int id)
{
	t_sprite_lst	*new_node;
	t_sprite_lst	*tmp_node;

	tmp_node = *head;
	new_node = (t_sprite_lst *)malloc(sizeof(t_sprite_lst));
	if (new_node == NULL)
		return (NULL);
    new_node->id = id;
	new_node->x = x;
	new_node->y = y;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;
	tmp_node->next = new_node;
	new_node->prev = tmp_node;
	return (new_node);
}

void	delete_node_sprite(t_sprite_lst **head, t_sprite_lst *del_node)
{
	if (*head == NULL || del_node == NULL)
		return ;
	if (*head == del_node)
		*head = del_node->next;
	if (del_node->next != NULL)
		del_node->next->prev = del_node->prev;
	if (del_node->prev != NULL)
		del_node->prev->next = del_node->next;
	ft_free(del_node);
	del_node = NULL;
}

void	delete_all_sprite(t_sprite_lst **head)
{
	t_sprite_lst	*tmp;

	if (*head == NULL)
		return ;
	tmp = *head;
	while (tmp != NULL)
	{
		delete_node_sprite(head, tmp);
		tmp = (*head)->next;
	}
	tmp = (*head)->next;
	delete_node_sprite(head, *head);
	*head = NULL;
}

int get_lst_size(t_sprite_lst *head)
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
