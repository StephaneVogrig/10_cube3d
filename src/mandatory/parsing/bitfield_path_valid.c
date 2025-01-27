/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitfield_path_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:01:23 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/27 15:58:43 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitfield_path_valid.h"

void	file_switch_key(t_fs *fs, char **key)
{
	if (ft_strcmp(*key, "NO") == 0)
		fs->no = 0;
	else if (ft_strcmp(*key, "SO") == 0)
		fs->so = 0;
	else if (ft_strcmp(*key, "WE") == 0)
		fs->we = 0;
	else if (ft_strcmp(*key, "EA") == 0)
		fs->ea = 0;
	else if (ft_strcmp(*key, "F") == 0)
		fs->f = 0;
	else if (ft_strcmp(*key, "C") == 0)
		fs->c = 0;
}

static inline void	file_switch_check(t_fs *fs, t_ui8 binarie)
{
	if (binarie == 0)
		fs->flag_double = 1;
}

int	file_switch_select(t_fs *fs, char *key)
{
	if (ft_strcmp(key, "NO") == 0)
		file_switch_check(fs, fs->no);
	else if (ft_strcmp(key, "SO") == 0)
		file_switch_check(fs, fs->so);
	else if (ft_strcmp(key, "WE") == 0)
		file_switch_check(fs, fs->we);
	else if (ft_strcmp(key, "EA") == 0)
		file_switch_check(fs, fs->ea);
	else if (ft_strcmp(key, "F") == 0)
		file_switch_check(fs, fs->f);
	else if (ft_strcmp(key, "C") == 0)
		file_switch_check(fs, fs->c);
	if (fs->flag_double == 1)
		return (ft_return(ERROR, 267, "Double Key"));
	return (SUCCESS);
}
