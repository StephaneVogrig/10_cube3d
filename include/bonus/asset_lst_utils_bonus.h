/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_lst_utils_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:38:57 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/28 14:39:56 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_LST_UTILS_BONUS_H
# define ASSET_LST_UTILS_BONUS_H

# include "asset_lst_bonus.h"

t_bool					asset_lst_key_exist(t_asset_lst *head, char key);
t_bool					asset_lst_key_in_list(t_asset_lst *head, char *key);

#endif