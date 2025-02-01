/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_to_asset_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:54:37 by aska              #+#    #+#             */
/*   Updated: 2025/02/01 17:19:08 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_TO_ASSET_BONUS_H
# define LSTMAP_TO_ASSET_BONUS_H

# include "libft.h"
# include "lstmap.h"
# include "lstmap_bonus.h"
# include "asset_lst_bonus.h"
# include "sprite_lst_bonus.h"
# include "key_value.h"
# include "parsing_utils.h"
# include "asset_lst_utils_bonus.h"
# include "coordinate.h"

int	lstmap_to_asset(t_lstmap **tmp, char *root_path, t_asset_lst **asset_lst,
		t_sprite_lst **sprite_lst);

#endif