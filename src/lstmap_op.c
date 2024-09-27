/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:37:02 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/09/26 16:16:21 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"
#include "lst_map.h"

void	insert_front_lstmap(t_lstmap **head, char *line)
{
	t_lstmap	*new_node;

	new_node = (t_lstmap *)malloc(sizeof(t_lstmap));
	new_node->line = line;
	new_node->next = (*head);
	new_node->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new_node;
	(*head) = new_node;
}

void	insert_after_lstmap(t_lstmap *prev_node, char *line)
{
	t_lstmap	*new_node;

	if (prev_node == NULL)
		ft_display(WARNING, "head is null, deletion is not possible");
	new_node = (t_lstmap *)malloc(sizeof(t_lstmap));
	new_node->line = line;
	new_node->next = prev_node->next;
	new_node->prev = prev_node;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

void	insert_end_lstmap(t_lstmap **head, char *line)
{
	t_lstmap	*new_node;
	t_lstmap	*tmp_node;

	tmp_node = *head;
	new_node = (t_lstmap *)malloc(sizeof(t_lstmap));
	new_node->line = line;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return ;
	}
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;
	tmp_node->next = new_node;
	new_node->prev = tmp_node;
}

void	display_lstmap(t_lstmap *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		ft_printf("%s", node->line);
		node = node->next;
		i++;
	}
}

void	explicit_display_all_dlst_node(t_lstmap *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		ft_printf("\nnode %i\t: %s\n", i, node->line);
		ft_printf("addr\t: %p\n", node);
		ft_printf("prev\t: %p\n", node->prev);
		ft_printf("next\t: %p\n", node->next);
		
		node = node->next;
		i++;
	}
}
