/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:35:07 by aska              #+#    #+#             */
/*   Updated: 2024/10/31 21:02:58 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utils.h"

int	setup_key_value_separate_by_space(char **key, char **value, char *line)
{
	*key = line;
	while (*line != '\0' && ft_isspace(*line) == FALSE)
		line++;
	if (*line == '\0')
		return (FAIL);
	*line = '\0';
	line++;
	while (ft_isspace(*line) == TRUE)
		line++;
	if (*line == '\0')
		return (FAIL);
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
	return (FAIL);
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

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (FALSE);
	while (line[i] != '\n')
	{
		if (line[i] != ' ')
			return (FALSE);
		i++;
	}
	return (TRUE);
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
