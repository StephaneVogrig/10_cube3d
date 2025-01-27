/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_lst_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:07:53 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 16:03:56 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_LST_BONUS_H
# define ASSET_LST_BONUS_H

# include "libft.h"

typedef struct s_asset_lst
{
	int					id;
	char				*key;
	t_bool				is_color;
	char				*value;
	struct s_asset_lst	*next;
	struct s_asset_lst	*prev;
}						t_asset_lst;

t_asset_lst				*insert_asset_lst(t_asset_lst **head, char *key,
							char *value, int id);
void					delete_node_asset(t_asset_lst **head,
							t_asset_lst *del_node);
void					delete_all_asset_lst(t_asset_lst **head);
t_bool					asset_lst_key_exist(t_asset_lst *head, char key);
t_bool					asset_lst_key_in_list(t_asset_lst *head, char *key);

#endif