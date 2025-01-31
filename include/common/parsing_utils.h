/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:17:12 by aska              #+#    #+#             */
/*   Updated: 2025/01/31 17:15:33 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_UTILS_H
# define PARSING_UTILS_H

# include "libft.h"

void	skip_blank(char **str);
int		is_empty(char *str);
void	remove_root_value(char *value);
int		is_map_valid(char *line);
int		get_root_path(char *map_path, char **root_path);

#endif