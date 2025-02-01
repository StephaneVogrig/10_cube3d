/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_lst_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:18:07 by aska              #+#    #+#             */
/*   Updated: 2025/02/01 17:38:16 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_lst_bonus.h"

static
t_asset_lst	*insert_asset_lst(t_asset_lst **head, char *key, char *value,
		int id)
{
	t_asset_lst	*new_node;
	t_asset_lst	*tmp_node;

	if (key == NULL || value == NULL)
		return (NULL);
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
	ft_free(del_node->key);
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

int	set_asset_lst(t_key_value *kv, char *root_path, t_asset_lst **asset_lst,
					int id)
{
	kv->value = ft_strtrim(kv->value, " ");
	if (kv->value == NULL)
		return (ft_return(ERROR, FAIL, "ft_strtrim failed", "set_asset_lst"));
	if (root_path != NULL && ft_strrchr(kv->value, '.') != NULL)
		kv->value = ft_strjoin_f2(root_path, kv->value);
	if (kv->value == NULL)
	{
		free(kv->value);
		return (ft_return(ERROR, FAIL, "ft_strjoin failed", "set_asset_lst"));
	}
	if (chk_open(kv->value) == FAIL && ft_strrchr(kv->value, '.') != NULL)
	{
		free(kv->value);
		return (ft_return(ERROR, FAIL, "failed to open asset", kv->key));
	}
	if (insert_asset_lst(asset_lst, kv->key, kv->value, id) == NULL)
	{
		free(kv->value);
		return (ft_return(ERROR, FAIL, "Insert failed", "set_asset_lst"));
	}
	return (SUCCESS);
}
