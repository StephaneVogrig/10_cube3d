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

# include "check_arg.h"
# include "file_utils.h"
# include "libft.h"
# include "lst_map.h"
# include "texture.h"

# define MSG_OPEN_ERROR "Error to open file"
# define MSG_CLOSE_ERROR "Error to close file"
# define MSG_LSTMAP_ERROR "Error to insert in lst_map"
# define MSG_GNL_ERROR "Error to read file"

typedef unsigned char	t_ui8;

typedef union
{
	struct
	{
		t_ui8 so : 1;
		t_ui8 we : 1;
		t_ui8 ea : 1;
		t_ui8 no : 1;
		t_ui8 f : 1;
		t_ui8 c : 1;
	};
	t_ui8				file_ok;
}						t_fs;

void					title(void);
void					print_tab(char **tab);
int						attrib_path(t_textures *tex, char *key, char *value);
int						lstmap_to_textures(t_textures *tex, t_lstmap **lst_map);
int						open_file(int *fd, char *file);
int						close_file(int *fd);
void					goto_exit(int check, int err, t_state state, char *msg);
int						setup_value(char *line, char *key, char **value);
int						setup_key(char *line, char **key);
int						file_to_lst_map(int fd, t_lstmap **lst_map);

#endif