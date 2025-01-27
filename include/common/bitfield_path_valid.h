/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitfield_path_valid.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:02:30 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/27 16:15:29 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITFIELD_PATH_VALID_H
# define BITFIELD_PATH_VALID_H

# include "libft.h"

typedef unsigned char	t_ui8;

typedef union u_fs
{
	struct
	{
		t_ui8	so : 1;
		t_ui8	we : 1;
		t_ui8	ea : 1;
		t_ui8	no : 1;
		t_ui8	f : 1;
		t_ui8	c : 1;
		t_ui8	flag_double : 1;
	};
	t_ui8				file_ok;
}						t_fs;

int						file_switch_select(t_fs *fs, char *key);
void					file_switch_key(t_fs *fs, char **key);

#endif