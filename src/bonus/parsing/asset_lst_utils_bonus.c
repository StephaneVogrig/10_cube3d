/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_lst_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:38:06 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/29 23:52:51 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_lst_utils_bonus.h"

t_bool	asset_lst_key_in_list(t_asset_lst *head, char *key)
{
	while (head)
	{
		if (ft_strcmp(head->key, key) == 0)
			return (TRUE);
		head = head->next;
	}
	return (FALSE);
}

static t_bool	chk_orientation_key(t_asset_lst *head)
{
	t_bool	orientation;

	orientation = asset_lst_key_in_list(head, "WE");
	orientation &= asset_lst_key_in_list(head, "EA");
	orientation &= asset_lst_key_in_list(head, "SO");
	orientation &= asset_lst_key_in_list(head, "NO");
	return (orientation);
}

static t_bool	chk_door_key(t_asset_lst *head, char key)
{
	char	key_tmp[3];
	t_bool	door;

	key_tmp[0] = key;
	key_tmp[1] = '\0';
	door = asset_lst_key_in_list(head, key_tmp);
	key_tmp[1] = 'E';
	key_tmp[2] = '\0';
	door &= asset_lst_key_in_list(head, key_tmp);
	return (door);
}

t_bool	asset_lst_key_exist(t_asset_lst *head, char key)
{
	char	key_tmp[3];

	if (ft_isthis(key, "NSEW") == TRUE)
		return (asset_lst_key_in_list(head, "F") && asset_lst_key_in_list(head,
				"C"));
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
		return (asset_lst_key_in_list(head, key_tmp));
	}
	return (chk_door_key(head, key));
}
