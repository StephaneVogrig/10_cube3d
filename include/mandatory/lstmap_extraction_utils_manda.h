/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils_manda.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:58:29 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/26 02:18:17 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_EXTRACTION_UTILS_MANDA_H
# define LSTMAP_EXTRACTION_UTILS_MANDA_H

# include "bitfield_path_valid.h"
# include "lstmap_extraction_manda.h"
# include "check_arg.h"

int				set_dict_key_value(t_dictionaries *kv, char *line, t_fs *fs);
int				set_color(t_color *rgb, char *value);
int				set_path_and_color(t_assets *tex,
					t_dictionaries *kv, char *root_path);
int				set_map_info(t_map *map, char *line);

#endif