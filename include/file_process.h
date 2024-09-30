/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_process.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:34:42 by aska              #+#    #+#             */
/*   Updated: 2024/09/29 10:03:31 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft-plus/libft.h"
# include "texture.h"

void	title(void);
void	print_tab(char **tab);
int		attrib_path(void *mlx, t_textures *tex, char *key, char *value);
int		file_process(void *mlx, t_textures *tex, int *fd);
int		check_entry_arg(int ac, char **av);
int		open_file(int *fd, char *file);
void	goto_exit(int check, int err, t_state state, char *msg);
int		setup_value(char *line, char *key, char **value);
int		setup_key(char *line, char **key);
int		path_seletor(void *mlx, t_textures *textures, char *key,
			char *img_path);

#endif