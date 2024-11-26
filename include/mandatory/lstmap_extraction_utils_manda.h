/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils_manda.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:58:29 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/26 16:34:48 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_EXTRACTION_UTILS_MANDA_H
# define LSTMAP_EXTRACTION_UTILS_MANDA_H

# include "assets.h"
# include "bitfield_path_valid.h"
# include "color.h"
# include "dictionarie.h"
# include "lstmap_extraction_manda.h"
# include "map.h"
// # include "check_arg.h"

int		set_dict_key_value(t_dictionaries *kv, char *line, t_fs *fs);
t_color	*set_color(char *value);
int		set_path_and_color(t_assets *tex, t_dictionaries *kv, char *root_path);
int		set_map_info(t_map *map, char *line);

#endif