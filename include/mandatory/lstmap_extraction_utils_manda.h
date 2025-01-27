/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils_manda.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:58:29 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/27 16:04:50 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_EXTRACTION_UTILS_MANDA_H
# define LSTMAP_EXTRACTION_UTILS_MANDA_H

# include "bitfield_path_valid.h"
# include "check_arg.h"
# include "map.h"
# include "textures_manda.h"

typedef struct s_key_value
{
	char	*key;
	char	*value;
}			t_key_value;

typedef struct s_tex_path
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}			t_tex_path;

int			set_key_value(t_key_value *kv, char *line, t_fs *fs);
int			set_rgb(t_rgb *rgb, char *value);
int			set_path_and_color(t_tex_path *tex_path, t_textures *tex,
				t_key_value *kv, char *root_path);
int			set_map_info(t_map *map, char *line);

#endif