/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_lst_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:18:07 by aska              #+#    #+#             */
/*   Updated: 2024/12/19 15:50:45 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_lst_bonus.h"

t_asset_lst	*insert_asset_lst(t_asset_lst **head, char *key, char *value,
		int id)
{
	t_asset_lst	*new_node;
	t_asset_lst	*tmp_node;

	tmp_node = *head;
	new_node = (t_asset_lst *)malloc(sizeof(t_asset_lst));
	if (new_node == NULL)
		return (NULL);
	new_node->key = key;
	new_node->value = value;
	new_node->id = id;
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

void	delete_node_asset(t_asset_lst **head, t_asset_lst *del_node)
{
	if (*head == NULL || del_node == NULL)
		return ;
	if (*head == del_node)
		*head = del_node->next;
	if (del_node->next != NULL)
		del_node->next->prev = del_node->prev;
	if (del_node->prev != NULL)
		del_node->prev->next = del_node->next;
	ft_free(del_node->value);
	ft_free(del_node);
	del_node = NULL;
}

void	delete_all_asset_lst(t_asset_lst **head)
{
	if (*head == NULL)
		return ;
	while (*head != NULL)
		delete_node_asset(head, *head);
	delete_node_asset(head, *head);
	*head = NULL;
}

void	print_asset_lst(t_asset_lst *head)
{
	t_asset_lst *tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("id: %d, key: %s, value: %s\n", tmp->id, tmp->key,
			tmp->value);
		tmp = tmp->next;
	}
}