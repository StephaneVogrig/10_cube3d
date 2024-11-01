/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:58:29 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/01 19:17:20 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_EXTRACTION_UTILS_H
# define LSTMAP_EXTRACTION_UTILS_H

# include "bitfield_path_valid.h"
# include "check_arg.h"
// # include "libft.h"
// # include "lst_map.h"
# include "parsing_utils.h"
# include "texture.h"
# include "map.h"

typedef struct s_key_value
{
	char		*key;
	char		*value;
}				t_key_value;

typedef struct s_tex_path
{
	t_key_value	*no;
	t_key_value	*so;
	t_key_value	*we;
	t_key_value	*ea;
}				t_tex_path;

int				set_key_value(t_key_value *kv, char *line, t_fs *fs);
int				attrib_rgb(t_rgb *rgb, char *value);
int				check_line(char *line);
int				attrib_path(t_textures *tex, t_key_value *kv, char *root_path);
int				set_map_info(t_map *map, char *line);

#endif