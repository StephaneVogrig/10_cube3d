/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:42:45 by aska              #+#    #+#             */
/*   Updated: 2024/09/30 19:54:52 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FILE_UTILS_H
# define FILE_UTILS_H

# include "file_process.h"
# include "texture.h"

int	texture_attribution(void *mlx, t_texture *tex, char *path);
int	path_seletor(void *mlx, t_textures *textures, char *key, char *img_path);
int	setup_key(char *line, char **key);
int	setup_value(char *line, char *key, char **value);
int	is_empty_line(char *line);
int	is_map_valid(char *line);

#endif