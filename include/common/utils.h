/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:28:21 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/02 14:34:02 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

char	choose_char(t_bool test, char val_if_true, char val_if_false);
float	choose_float(t_bool test, float val_if_true, float val_if_false);
int		get_root_path(char *map_path, char **root_path);
void	remove_root_value(char *value);

#endif