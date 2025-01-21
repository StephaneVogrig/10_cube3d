/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_lst_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:18:07 by aska              #+#    #+#             */
/*   Updated: 2025/01/21 18:57:35 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_lst_bonus.h"

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

t_bool	assetlst_key_found(t_asset_lst *assetlst, char *key)
{
	while(assetlst)
	{
		if (ft_strcmp(assetlst->key, key) == 0)
			return (TRUE);
		assetlst = assetlst->next;
	}
	return (FALSE);
}

static t_bool chk_orientation_key(t_asset_lst *head)
{
	t_bool		orientation;

	orientation = assetlst_key_found(head, "WE");
	orientation &= assetlst_key_found(head, "EA");
	orientation &= assetlst_key_found(head, "SO");
	orientation &= assetlst_key_found(head, "NO");
	return (orientation);
}

static t_bool chk_door_key(t_asset_lst *head, char key)
{
	char		key_tmp[3];
	t_bool		door;

	key_tmp[0] = key;
	key_tmp[1] = '\0';
	door = assetlst_key_found(head, key_tmp);
	key_tmp[1] = 'E';
	key_tmp[2] = '\0';
	door &= assetlst_key_found(head, key_tmp);
	return(door);
}

t_bool	asset_lst_key_exist(t_asset_lst *head, char key)
{
	char		key_tmp[3];

	if (key == '0')
		return (assetlst_key_found(head, "F") && assetlst_key_found(head, "C"));
	if (key == '1')
	{
		if (chk_orientation_key(head))
			return (TRUE);
	}
	if (ft_isdigit(key) == TRUE)
	{
		key_tmp[0] = 'W';
		key_tmp[1] = key;
		key_tmp[2] = '\0';
		return (assetlst_key_found(head, key_tmp));
	}
	return (chk_door_key(head, key));
}
