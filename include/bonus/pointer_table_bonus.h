/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_table_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 04:15:42 by aska              #+#    #+#             */
/*   Updated: 2025/02/02 12:16:49 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTER_TABLE_BONUS_H
# define POINTER_TABLE_BONUS_H

# include "asset_bonus.h"
# include "libft.h"
# include "door_bonus.h"

void		pointer_table_init(t_asset *asset);
t_texture	*asset_get_texture_ptr(t_asset *t, char *cell, char orientation);

#endif