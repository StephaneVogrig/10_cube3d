/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_lst_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:07:53 by aska              #+#    #+#             */
/*   Updated: 2025/02/01 17:39:20 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_LST_BONUS_H
# define ASSET_LST_BONUS_H

# include "libft.h"
# include "key_value.h"
# include "check_arg.h"

typedef struct s_asset_lst
{
	int					id;
	char				*key;
	t_bool				is_color;
	char				*value;
	struct s_asset_lst	*next;
	struct s_asset_lst	*prev;
}						t_asset_lst;

void					delete_node_asset(t_asset_lst **head,
							t_asset_lst *del_node);
void					delete_all_asset_lst(t_asset_lst **head);
int						set_asset_lst(t_key_value *kv, char *root_path,
							t_asset_lst **asset_lst, int id);

#endif