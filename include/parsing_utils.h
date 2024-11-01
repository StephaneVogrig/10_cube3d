/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:42:45 by aska              #+#    #+#             */
/*   Updated: 2024/11/01 18:05:43 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_UTILS_H
# define FILE_UTILS_H

# include "lstmap_extraction_utils.h"
# include "texture.h"

int		setup_key_value_separate_by_space(char *key, char *value, char *line);
int		is_empty(char *str);
void	remove_root_value(char *value);
int		is_map_valid(char *line);

#endif