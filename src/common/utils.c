/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:30:48 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/03 13:48:31 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	choose_char(t_bool test, char val_if_true, char val_if_false)
{
	if (test == TRUE)
		return (val_if_true);
	return (val_if_false);
}

float	choose_float(t_bool test, float val_if_true, float val_if_false)
{
	if (test == TRUE)
		return (val_if_true);
	return (val_if_false);
}

int	get_root_path(char *map_path, char **root_path)
{
	*root_path = ft_strrchr(map_path, '/');
	if (*root_path != NULL)
		*root_path = ft_substr(map_path, 0, *root_path - map_path + 1);
	else
		*root_path = ft_strdup("./");
	if (*root_path == NULL)
		return (ft_return(ERROR, 3, "malloc error", "get_root_path"));
	return (SUCCESS);
}
