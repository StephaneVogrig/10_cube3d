/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:17:12 by aska              #+#    #+#             */
/*   Updated: 2025/02/02 14:34:16 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_UTILS_H
# define PARSING_UTILS_H

# include "libft.h"

char	*spacetrim(char *str);
void	skip_blank(char **str);
int		is_empty(char *str);
int		is_map_valid(char *line);

#endif