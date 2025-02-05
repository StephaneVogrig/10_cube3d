/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:30:56 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/02/05 22:22:10 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_EXTRACTION_BONUS_H
# define LSTMAP_EXTRACTION_BONUS_H

# include "asset_lst_bonus.h"
# include "check_asset_bonus.h"
# include "coordonate_bonus.h"
# include "file_load.h"
# include "lstmap.h"
# include "map.h"
# include "parsing_utils.h"
# include "sprite_lst_bonus.h"
# include "lstmap_to_asset_bonus.h"

int	lstmap_extract_info(t_map *map, char *map_path, t_asset_lst **asset_lst,
		t_sprite_lst **sprite_lst);
int	lstmap_to_grid(t_map *map, t_lstmap **lst_map);

#endif