/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:37:02 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/10/26 17:29:24 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_map.h"

t_lstmap	*insert_end_lstmap(t_lstmap **head, char *line)
{
	t_lstmap	*new_node;
	t_lstmap	*tmp_node;

	tmp_node = *head;
	new_node = (t_lstmap *)malloc(sizeof(t_lstmap));
	if (new_node == NULL)
		return (NULL);
	new_node->line = line;
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

void	delete_node_lstmap(t_lstmap **head, t_lstmap *del_node)
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

void	delete_all_lstmap(t_lstmap **head)
{
	t_lstmap	*tmp;

	if (*head == NULL)
	{
		ft_display(WARNING, "head is null, deletion is not possible");
		return ;
	}
	tmp = *head;
	while (tmp != NULL)
	{
		delete_node_lstmap(head, tmp);
		tmp = (*head)->next;
	}
	tmp = (*head)->next;
	delete_node_lstmap(head, *head);
	*head = NULL;
}