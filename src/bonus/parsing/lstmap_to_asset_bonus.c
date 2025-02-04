/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_to_asset_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:53:06 by aska              #+#    #+#             */
/*   Updated: 2025/02/04 13:19:06 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_to_asset_bonus.h"

static
t_status	chk_syntax_key(char *key)
{
	if (key[0] == 'N' && key[1] == 'O')
		return (SUCCESS);
	else if (key[0] == 'S' && (key[1] == 'O' || key[1] == 'P'))
		return (SUCCESS);
	else if (key[0] == 'E' && key[1] == 'A')
		return (SUCCESS);
	else if (ft_isthis(key[0], "FC") == TRUE && key[1] == '\0')
		return (SUCCESS);
	else if (ft_isthis(key[0], "RLT") && (key[1] == '\0' || key[1] == 'E'))
		return (SUCCESS);
	else if (key[0] == 'W' && ft_isthis(key[1], "E123456789"))
		return (SUCCESS);
	return (FAIL);
}

static
t_status	chk_key(t_key_value *kv, t_asset_lst **asset_lst)
{
	if (chk_syntax_key(kv->key) == FAIL)
		return (ft_return(ERROR, FAIL, "Invalid key", kv->key));
	if (ft_strcmp(kv->key, "SP") && key_is_in_asset_lst(*asset_lst, kv->key))
		return (ft_return(ERROR, FAIL, "Key already exist", kv->key));
	return (SUCCESS);
}

int	lstmap_to_asset(t_lstmap **lstmap, char *root_path, t_asset_lst **asset_lst,
		t_sprite_lst **sprite_lst)
{
	t_key_value	kv;
	int			exit_code;
	int			id;

	id = 0;
	exit_code = SUCCESS;
	while (next_valid_asset(lstmap, &exit_code) == TRUE)
	{
		exit_code = set_key_value(&kv, (*lstmap)->line);
		if (exit_code == SUCCESS)
			exit_code = chk_key(&kv, asset_lst);
		if (exit_code == SUCCESS)
			exit_code = set_asset_lst(&kv, root_path, asset_lst, id);
		if (exit_code != SUCCESS)
			break ;
		(*lstmap)->line = NULL;
		if (kv.key != NULL && ft_strcmp(kv.key, "SP") == 0)
			exit_code = extract_coordinate_sprite(sprite_lst, lstmap, id);
		else
			*lstmap = (*lstmap)->next;
		if (exit_code != SUCCESS)
			break ;
		id++;
	}
	return (exit_code);
}
