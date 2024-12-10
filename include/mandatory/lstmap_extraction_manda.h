/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_manda.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:30:56 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/12/03 16:02:37 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_EXTRACTION_MANDA_H
# define LSTMAP_EXTRACTION_MANDA_H

# include "assets.h"
# include "bitfield_path_valid.h"
# include "check_arg.h"
# include "file_load.h"
# include "lst_map.h"
# include "lstmap_extraction_utils_manda.h"
# include "map.h"
# include "parsing_utils.h"

int	lstmap_extract_info(t_dictionarie *tex, t_map *map, t_lstmap **head, char *map_path);
int	lstmap_to_path_and_color(t_assets *assets, t_lstmap **lst_map, char *root_path);
int	lstmap_to_grid(t_map *map, t_lstmap **lst_map);
int	check_all_validity_line(t_map *map, t_lstmap **lst_map);

#endif
