/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_to_asset_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:53:06 by aska              #+#    #+#             */
/*   Updated: 2025/01/31 14:22:51 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_to_asset_bonus.h"

static int	set_asset_lst(t_key_value *kv, 
							char *root_path, 
							t_asset_lst **asset_lst,
							int id)
{
	int	fd;

	kv->value = ft_strtrim(kv->value, " ");
	if (kv->value != NULL && ft_strrchr(kv->value, '.') == NULL)
	{
		if (insert_asset_lst(asset_lst, kv->key, kv->value, id) == NULL)
			return (ft_return(ERROR, FAIL, "malloc failed", "set_asset_lst"));
		return (SUCCESS);
	}
	if (kv->value != NULL && root_path != NULL)
		kv->value = ft_strjoin_f2(root_path, kv->value);
	if (kv->value == NULL)
		return (ft_return(ERROR, FAIL, "malloc failed", "set_asset_lst"));
	fd = open(kv->value, O_RDONLY);
	if (fd == FAIL)
	{
		kv->value = ft_char_f(kv->value);
		return (ft_return(ERROR, FAIL, "open failed for asset file", kv->key));
	}
	close(fd);
	if (insert_asset_lst(asset_lst, kv->key, kv->value, id) == NULL)
		return (ft_return(ERROR, FAIL, "malloc failed", "set_asset_lst"));
	return (SUCCESS);
}

static t_bool	is_asset_valid(t_lstmap **tmp)
{
	while (*tmp != NULL && is_empty((*tmp)->line) == TRUE)
		*tmp = (*tmp)->next;
	if (*tmp == NULL)
		return (FALSE);
	if (!ft_isthis((*tmp)->line[0], "NWESFCTLR"))
		return (FALSE);
	if (!ft_isthis((*tmp)->line[1], "EAOP 123456789"))
		return (FALSE);
	if (ft_strlen_endc((*tmp)->line, ' ') > 2)
		return (FALSE);
	return (TRUE);
}

static t_status	chk_key(char *key)
{
	if (key[0] == 'N' && ft_strcmp(key, "NO") != 0)
		return (ft_return(ERROR, FAIL, "invalid key", key));
	else if (key[0] == 'S')
	{
		if (ft_strcmp(key, "SO") != 0 && ft_strcmp(key, "SP") != 0)
			return (ft_return(ERROR, FAIL, "invalid key", key));
	}
	else if (key[0] == 'E' && ft_strcmp(key, "EA") != 0)
		return (ft_return(ERROR, FAIL, "invalid key", key));
	else if (ft_isthis(key[0], "FC") == TRUE && key[1] != '\0')
		return (ft_return(ERROR, FAIL, "invalid key", key));
	else if (ft_isthis(key[0], "RLT") == TRUE)
	{
		if (key[1] == '\0' || key[1] == 'E')
			return (SUCCESS);
		return (ft_return(ERROR, FAIL, "invalid key", key));
	}
	else if (key[0] == 'W' && ft_isthis(key[1], "E123456789") != TRUE)
		return (ft_return(ERROR, FAIL, "invalid key", key));
	return (SUCCESS);
}

static t_status chk_key_value(t_key_value *kv, t_asset_lst **asset_lst)
{
    if (chk_key(kv->key) == FAIL)
		return (FAIL);
	if (ft_strcmp(kv->key, "SP") != 0 && asset_lst_key_in_list(*asset_lst,
			kv->key) == TRUE)
		return (ft_return(ERROR, FAIL, "Key already exist", kv->key));
	remove_root_value(kv->value);
	return (SUCCESS);
}

int	lstmap_to_asset(t_lstmap **tmp, char *root_path,
		t_asset_lst **asset_lst, t_sprite_lst **sprite_lst)
{
	t_key_value	kv;
	int			exit_code;
	int			id;

	id = 0;
	exit_code = SUCCESS;
	while (tmp != NULL && exit_code == SUCCESS && is_asset_valid(tmp) != FALSE)
	{
		exit_code = set_key_value(&kv, (*tmp)->line);
        if (exit_code == SUCCESS)
            exit_code = chk_key_value(&kv, asset_lst);
		if (exit_code == SUCCESS)
			exit_code = set_asset_lst(&kv, root_path, asset_lst, id);
		if (exit_code != SUCCESS)
			break ;
		(*tmp)->line = NULL;
		if (kv.key != NULL && ft_strcmp(kv.key, "SP") == 0)
			exit_code = extract_coordinate_sprite(sprite_lst, tmp, id);
		else if (exit_code == SUCCESS)
			*tmp = (*tmp)->next;
		id++;
	}
	return (exit_code);
}
