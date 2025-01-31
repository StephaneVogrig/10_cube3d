/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_manda.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:30:56 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/31 17:20:45 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_EXTRACTION_MANDA_H
# define LSTMAP_EXTRACTION_MANDA_H

# include "file_load.h"
# include "lstmap.h"
# include "lstmap_utils.h"
# include "map.h"
# include "parsing_utils.h"
# include "textures_manda.h"
# include "tex_path_manda.h"
# include "bitfield_path_valid.h"
# include "check_arg.h"

int	lstmap_extract_info(t_textures *textures, t_map *map, t_tex_path *tex_path,
		char *map_path);

#endif
