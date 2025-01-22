/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils_bonus.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:58:29 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/22 21:14:47 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_EXTRACTION_UTILS_BONUS_H
# define LSTMAP_EXTRACTION_UTILS_BONUS_H

# include "asset_lst_bonus.h"
# include "check_arg.h"
# include "color.h"
# include "parsing_utils.h"
# include "sprite_lst_bonus.h"
# include "libft.h"

typedef struct s_key_value
{
	char	*key;
	char	*value;
}			t_key_value;

typedef struct s_tex_path
{
	char	*path[14];
}			t_tex_path;

int		set_key_value(t_key_value *kv, char *line, t_asset_lst **asset_lst);
int		set_rgb(t_rgb *rgb, char *value);
int		check_line(char *line);
int		set_asset_lst(t_key_value *kv, char *root_path, t_asset_lst **asset_lst, int id);

#endif