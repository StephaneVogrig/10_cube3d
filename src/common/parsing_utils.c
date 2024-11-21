/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:35:07 by aska              #+#    #+#             */
/*   Updated: 2024/11/01 14:37:36 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

int	setup_key_value_separate_by_space(char **key, char **value, char *line)
{
	*key = line;
	while (*line != '\0' && ft_isspace(*line) == FALSE)
		line++;
	if (*line == '\0')
		return (ft_return(ERROR, 264, "Invalid Key"));
	*line = '\0';
	line++;
	while (ft_isspace(*line) == TRUE)
		line++;
	if (*line == '\0')
		return (ft_return(ERROR, 265, "Invalid Value"));
	*value = line;
	while (*line != '\0' && ft_isspace(*line) == FALSE)
		line++;
	if (*line == '\0')
		return (SUCCESS);
	*line = '\0';
	line++;
	while (ft_isspace(*line) == TRUE)
		line++;
	if (*line == '\0')
		return (SUCCESS);
	return (ft_return(ERROR, 266, "Invalid Value"));
}

int	is_empty(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (FALSE);
		str++;
	}
	return (TRUE);
}

char	*get_root_path(char *path)
{
	char	*root_path;

	root_path = ft_strrchr(path, '/');
	if (root_path == NULL)
		return (NULL);
	return (ft_substr(path, 0, root_path - path + 1));
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
