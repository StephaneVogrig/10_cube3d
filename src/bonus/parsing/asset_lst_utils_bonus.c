/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_lst_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:38:06 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/28 14:40:22 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_lst_utils_bonus.h"

static t_bool	assetlst_key_found(t_asset_lst *assetlst, char *key)
{
	while (assetlst)
	{
		if (ft_strcmp(assetlst->key, key) == 0)
			return (TRUE);
		assetlst = assetlst->next;
	}
	return (FALSE);
}

static t_bool	chk_orientation_key(t_asset_lst *head)
{
	t_bool	orientation;

	orientation = assetlst_key_found(head, "WE");
	orientation &= assetlst_key_found(head, "EA");
	orientation &= assetlst_key_found(head, "SO");
	orientation &= assetlst_key_found(head, "NO");
	return (orientation);
}

static t_bool	chk_door_key(t_asset_lst *head, char key)
{
	char	key_tmp[3];
	t_bool	door;

	key_tmp[0] = key;
	key_tmp[1] = '\0';
	door = assetlst_key_found(head, key_tmp);
	key_tmp[1] = 'E';
	key_tmp[2] = '\0';
	door &= assetlst_key_found(head, key_tmp);
	return (door);
}

t_bool	asset_lst_key_exist(t_asset_lst *head, char key)
{
	char	key_tmp[3];

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
