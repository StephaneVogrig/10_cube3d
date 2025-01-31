/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:52:01 by aska              #+#    #+#             */
/*   Updated: 2025/01/31 13:25:01 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

int	get_root_path(char *map_path, char **root_path)
{
	*root_path = ft_strrchr(map_path, '/');
	if (*root_path != NULL)
	{
		*root_path = ft_substr(map_path, 0, *root_path - map_path + 1);
		if (*root_path == NULL)
			return (ft_return(ERROR, 3, "malloc error", "get_root_path"));
	}
	else
	{
		*root_path = ft_strdup("./");
		if (*root_path == NULL)
			return (ft_return(ERROR, 3, "malloc error", "get_root_path"));
	}
	return (SUCCESS);
}

int	is_empty(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str) == FALSE)
			return (FALSE);
		str++;
	}
	return (TRUE);
}

void	remove_root_value(char *value)
{
	char	*tmp_value;

	tmp_value = ft_strchr(value, '/');
	if (tmp_value != NULL)
		value = tmp_value + 1;
}

int	is_map_valid(char *line)
{
	int	i;

	if (line == NULL)
		return (FALSE);
	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isthis(line[i], " 01NSEW\n") == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
