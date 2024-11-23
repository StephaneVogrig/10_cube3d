/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:58:29 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/23 15:06:23 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef LSTMAP_EXTRACTION_UTILS_H
# define LSTMAP_EXTRACTION_UTILS_H

# include "bitfield_path_valid.h"
# include "check_arg.h"
# include "map.h"
# include "texture_manda.h"

typedef struct s_key_value
{
	char		*key;
	char		*value;
}				t_key_value;

typedef struct s_tex_path
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}				t_tex_path;

int				set_key_value(t_key_value *kv, char *line, t_fs *fs);
int				attrib_rgb(t_rgb *rgb, char *value);
int				set_path_and_color(t_tex_path *tex_path, t_textures *tex,
					t_key_value *kv, char *root_path);
int				set_map_info(t_map *map, char *line);

#endif