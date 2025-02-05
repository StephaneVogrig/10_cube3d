/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_utils_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:48:47 by aska              #+#    #+#             */
/*   Updated: 2025/02/05 15:00:36 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_UTILS_BONUS_H
# define ASSET_UTILS_BONUS_H

# include "asset_bonus.h"

int		get_asset_lst_size(t_asset_lst *head);
void	asset_buffer_destroy(t_texture *t);
int		asset_set_key_value(t_asset *asset, char *key, int size, int i);

#endif
