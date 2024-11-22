/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:30:56 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/22 01:19:31 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_EXTRACTION_BONUS_H
# define LSTMAP_EXTRACTION_BONUS_H

# include "lst_map.h"
# include "lstmap_extraction_utils_bonus.h"
# include "map.h"
# include "parsing_utils.h"

int	lstmap_extract_info(t_lstmap **lst_map, t_map *map, t_tex_path *tex_path,
		char *map_path);
int	lstmap_to_path_and_color(t_tex_path *tex_path, t_lstmap **lst_map,
		char *root_path);
int	lstmap_to_grid(t_map *map, t_lstmap **lst_map);
int	check_all_validity_line(t_map *map, t_lstmap **lst_map);

#endif