/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils_bonus.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:58:29 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/26 01:50:06 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_EXTRACTION_UTILS_BONUS_H
# define LSTMAP_EXTRACTION_UTILS_BONUS_H

# include "check_arg.h"
# include "parsing_utils.h"
# include "id_tex_bonus.h"
# include "color.h"

typedef struct s_tex_path
{
	char	*path[14];
}			t_tex_path;

int			set_dict_key_value(t_dictionaries *kv, char *line);
int			set_color(t_color *rgb, char *value);
int			check_line(char *line);
int			set_path_and_color(t_tex_path *tex_path, t_dictionaries *kv,
				char *root_path);

#endif