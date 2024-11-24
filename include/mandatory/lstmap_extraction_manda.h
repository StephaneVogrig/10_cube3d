/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_manda.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:30:56 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/23 18:36:13 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef LSTMAP_EXTRACTION_MANDA_H
# define LSTMAP_EXTRACTION_MANDA_H

# include "lst_map.h"
# include "lstmap_extraction_utils_manda.h"
# include "map_manda.h"
# include "parsing_utils.h"

int		lstmap_extract_info(t_lstmap **lst_map, t_map *map,
			t_tex_path *tex_path, char *map_path);
int		lstmap_to_path_and_color(t_tex_path *tex_path, t_textures *tex,
			t_lstmap **lst_map, char *root_path);
int		lstmap_to_grid(t_map *map, t_lstmap **lst_map);
int		check_all_validity_line(t_map *map, t_lstmap **lst_map);

#endif