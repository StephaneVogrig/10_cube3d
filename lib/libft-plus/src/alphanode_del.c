/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphanode_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:37:02 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/30 17:38:13 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	delete_alphanode(t_alphanode **head, t_alphanode *del_node)
{
	if (*head == NULL || del_node == NULL)
		return ;
	if (*head == del_node)
		*head = del_node->next;
	if (del_node->next != NULL)
		del_node->next->prev = del_node->prev;
	if (del_node->prev != NULL)
		del_node->prev->next = del_node->next;
	free(del_node);
	del_node = NULL;
}

void	delete_all_alphanodes(t_alphanode **head)
{
	t_alphanode	*tmp;

	if (*head == NULL)
	{
		ft_display(WARNING, "head is null, deletion is not possible");
		return ;
	}
	while (*head != NULL)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}
