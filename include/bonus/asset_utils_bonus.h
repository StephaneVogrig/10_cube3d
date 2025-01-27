/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_utils_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:48:47 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 16:03:58 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_UTILS_BONUS_H
# define ASSET_UTILS_BONUS_H

# include "asset_bonus.h"

int		get_asset_lst_size(t_asset_lst *head);
void	asset_buffer_destroy(t_texture *t);
int		asset_set_key_value(t_asset *asset, char *key, int size, int i);
int		color_to_buffer(t_rgb *rgb, t_texture *t);

#endif
