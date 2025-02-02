/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_lst_utils_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:38:57 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/02/02 13:47:12 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_LST_UTILS_BONUS_H
# define ASSET_LST_UTILS_BONUS_H

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

char	*spacetrim(char *str);
t_bool	asset_lst_key_exist(t_asset_lst *head, char key);
t_bool	key_is_in_asset_lst(t_asset_lst *head, char *key);

#endif