/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils_bonus.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:58:29 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/25 19:27:12 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_EXTRACTION_UTILS_BONUS_H
# define LSTMAP_EXTRACTION_UTILS_BONUS_H

# include "check_arg.h"
# include "parsing_utils.h"
# include "id_tex_bonus.h"
# include "color.h"

typedef struct s_key_value
{
	char	*key;
	char	*value;
}			t_key_value;

typedef struct s_tex_path
{
	char	*path[14];
}			t_tex_path;

int			set_key_value(t_key_value *kv, char *line);
int			attrib_rgb(t_rgb *rgb, char *value);
int			check_line(char *line);
int			set_path_and_color(t_tex_path *tex_path, t_key_value *kv,
				char *root_path);

#endif