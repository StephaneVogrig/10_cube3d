/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_load.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:38:56 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/02/04 15:28:56 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_LOAD_H
# define FILE_LOAD_H

# include "lstmap.h"
# include "file_utils.h"

# define MSG_OPEN_ERROR "Error to open file"
# define MSG_CLOSE_ERROR "Error to close file"
# define MSG_LSTMAP_ERROR "Error to insert in lst_map"
# define MSG_GNL_ERROR "Error to read file"

int		file_load(char *path, t_lstmap **lst_map);
int		open_file(int *fd, char *file);
int		close_file(int *fd);
void	replace_eol_to_nul(char *str);
int		file_to_lst_map(int fd, t_lstmap **lst_map);

#endif