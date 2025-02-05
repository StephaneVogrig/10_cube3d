/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_lst_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:18:07 by aska              #+#    #+#             */
/*   Updated: 2025/02/05 20:51:10 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_lst_bonus.h"

static t_asset_lst	*insert_asset_lst(t_asset_lst **head, char *key,
		char *value, int id)
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
}

static int	check_path(char *root_path, t_key_value *kv)
{
	if (root_path != NULL)
		kv->value = ft_strjoin(root_path, kv->value);
	else
		kv->value = ft_strdup(kv->value);
	if (kv->value == NULL)
		return (ft_return(ERROR, FAIL, "malloc failed", "set_asset_lst"));
	if (is_folder(kv->value) == TRUE)
	{
		free(kv->value);
		return (ft_return(ERROR, FAIL, kv->key, " assset is a folder"));
	}
	if (chk_open(kv->value) == FAIL && ft_strrchr(kv->value, '.') != NULL)
	{
		free(kv->value);
		return (ft_return(ERROR, FAIL, "failed to open asset", kv->key));
	}
	return (SUCCESS);
}

int	set_asset_lst(t_key_value *kv, char *root_path, t_asset_lst **asset_lst,
		int id)
{
	t_rgb	rgb;

	kv->value = spacetrim(kv->value);
	if (ft_strrchr(kv->value, '.') == NULL)
	{
		if (color_set_rgb(&rgb, kv->value) == FAIL)
			return (FAIL);
		kv->value = ft_strdup(kv->value);
		if (kv->value == NULL)
			return (ft_return(ERROR, FAIL, "malloc failed", "set_asset_lst"));
	}
	else if (check_path(root_path, kv) == FAIL)
		return (FAIL);
	if (insert_asset_lst(asset_lst, kv->key, kv->value, id) == NULL)
	{
		free(kv->value);
		return (ft_return(ERROR, FAIL, "Insert failed", "set_asset_lst"));
	}
	return (SUCCESS);
}
