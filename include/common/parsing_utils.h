/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:17:12 by aska              #+#    #+#             */
/*   Updated: 2025/01/30 01:48:33 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_UTILS_H
# define PARSING_UTILS_H

# include "libft.h"

int		setup_key_value_separate_by_space(char **key, char **value, char *line);
int		is_empty(char *str);
void	remove_root_value(char *value);
int		is_map_valid(char *line);
int		get_root_path(char *map_path, char **root_path);


#endif