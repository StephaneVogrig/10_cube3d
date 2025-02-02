/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_lst_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:07:53 by aska              #+#    #+#             */
/*   Updated: 2025/02/02 13:48:26 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_LST_BONUS_H
# define ASSET_LST_BONUS_H

# include "libft.h"
# include "key_value.h"
# include "check_arg.h"
# include "asset_lst_utils_bonus.h"

void	delete_node_asset(t_asset_lst **head, t_asset_lst *del_node);
void	delete_all_asset_lst(t_asset_lst **head);
int		set_asset_lst(t_key_value *kv, char *root_path, t_asset_lst **asset_lst,
			int id);

#endif