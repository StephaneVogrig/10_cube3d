/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 09:37:11 by aska              #+#    #+#             */
/*   Updated: 2025/02/04 15:35:20 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ARG_H
# define CHECK_ARG_H

# include "libft.h"
# include "parsing_utils.h"
# include "file_utils.h"

# define EXTENSION_FILE ".cub"
# define NUM_OF_ARG "Number of entry arguments"
# define INVALID_NUM_OF_ARG "Invalid number of arguments"
# define TITLE_FILE_EXT "File extension"
# define NO_CUB_EXT "No \".cub\" extension map file"

int	check_entry_arg(int ac, char **av);
int	check_line(char *line);
int	chk_open(char *path);

#endif