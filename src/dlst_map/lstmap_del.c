/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:37:02 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/09/07 16:25:01 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../include/cub3d.h"

void	delete_lstmap(t_lstmap **head, t_lstmap *del_node)
{
	if (*head == NULL || del_node == NULL)
		return ;
	if (*head == del_node)
		*head = del_node->next;
	if (del_node->next != NULL)
		del_node->next->prev = del_node->prev;
	if (del_node->prev != NULL)
		del_node->prev->next = del_node->next;
	ft_free(del_node->line);
	del_node->line = NULL;
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
		delete_lstmap(head, tmp);
		tmp = (*head)->next;
	}
	tmp = (*head)->next;
	delete_lstmap(head, *head);
	*head = NULL;
}
