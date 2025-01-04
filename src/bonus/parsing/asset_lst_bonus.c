/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_lst_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:18:07 by aska              #+#    #+#             */
/*   Updated: 2025/01/03 18:20:59 by aska             ###   ########.fr       */
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

static t_bool chk_orientation_key(t_asset_lst *head)
{
	t_bool		orientation;

	orientation = asset_lst_key_exist(head, 'W');
	orientation &= asset_lst_key_exist(head, 'E');
	orientation &= asset_lst_key_exist(head, 'S');
	orientation &= asset_lst_key_exist(head, 'N');
	return (orientation);
}

t_bool	asset_lst_key_exist(t_asset_lst *head, char key)
{
	t_asset_lst	*tmp;
	char		key_tmp[2];
	t_bool		f_c_chk;
	
	key_tmp[0] = 'W';
	key_tmp[1] = key;
	tmp = head;
	if (key == '0')
	{
		f_c_chk = asset_lst_key_exist(head, 'F');
		f_c_chk &= asset_lst_key_exist(head, 'C');
			return (f_c_chk);
	}
	while (tmp != NULL)
	{
		if (ft_isdigit(key) == TRUE && ft_strcmp(tmp->key, key_tmp) == 0)
			return (TRUE);
		else if (tmp->key[0] == key)
			return (TRUE);
		tmp = tmp->next;
	}
	if (key == '1')
		return (chk_orientation_key(head));
	
	return (FALSE);
}
