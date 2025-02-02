/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_lst_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:38:06 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/02/02 14:02:50 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_lst_utils_bonus.h"

t_bool	key_is_in_asset_lst(t_asset_lst *head, char *key)
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

	orientation = key_is_in_asset_lst(head, "WE");
	orientation &= key_is_in_asset_lst(head, "EA");
	orientation &= key_is_in_asset_lst(head, "SO");
	orientation &= key_is_in_asset_lst(head, "NO");
	return (orientation);
}

static t_bool	chk_door_key(t_asset_lst *head, char key)
{
	char	key_tmp[3];
	t_bool	door;

	key_tmp[0] = key;
	key_tmp[1] = '\0';
	door = key_is_in_asset_lst(head, key_tmp);
	key_tmp[1] = 'E';
	key_tmp[2] = '\0';
	door &= key_is_in_asset_lst(head, key_tmp);
	return (door);
}

t_bool	asset_lst_key_exist(t_asset_lst *head, char key)
{
	char	key_tmp[3];

	if (ft_isthis(key, "NSEW") == TRUE)
		return (key_is_in_asset_lst(head, "F") && key_is_in_asset_lst(head,
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
		return (key_is_in_asset_lst(head, key_tmp));
	}
	return (chk_door_key(head, key));
}
