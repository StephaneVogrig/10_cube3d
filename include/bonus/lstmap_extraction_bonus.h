/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:30:56 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/12/10 14:34:33 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_EXTRACTION_BONUS_H
# define LSTMAP_EXTRACTION_BONUS_H

# include "lst_map.h"
# include "map.h"
# include "parsing_utils.h"
# include "file_load.h"
# include "lstmap_extraction_utils_bonus.h"

int	lstmap_extract_info(t_map *map, t_tex_path *tex_path, char *map_path);
int	lstmap_to_grid(t_map *map, t_lstmap **lst_map);
int	check_line_remain(t_map *map, t_lstmap **lst_map);

#endif