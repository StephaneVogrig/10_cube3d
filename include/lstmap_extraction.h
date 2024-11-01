/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:30:56 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/01 19:19:35 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_EXTRACTION_H
# define LSTMAP_EXTRACTION_H

# include "lst_map.h"
# include "map.h"
# include "parsing_utils.h"

int		lstmap_extraction_info(t_lstmap **lst_map, t_map *map, char *map_path);
int		lstmap_to_path_and_color(t_textures *tex, t_lstmap **lst_map,
			char *root_path);
int		lstmap_to_grid(t_map *map, t_lstmap **lst_map);
int		check_all_validity_line(t_map *map, t_lstmap **lst_map);
char	*get_root_path(char *path);

#endif