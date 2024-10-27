/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:35:07 by aska              #+#    #+#             */
/*   Updated: 2024/10/27 14:54:17 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utils.h"


int	setup_key(char *line, char **key)
{
	*key = ft_substr(line, 0, ft_strlen_endc(line, ' '));
	if (*key == NULL)
		return (ft_return(ERROR, FAIL, "Allocating key failed"));
	return (SUCCESS);
}

int	setup_value(char *line, char *key, char **value)
{
	int	key_len;

	key_len = ft_strlen(key);
	*value = ft_substr(line, key_len, ft_strlen_endc(line + key_len, '\n'));
	if (*value == NULL)
		return (ft_return(ERROR, FAIL, "Allocating texture path failed"));
	return (SUCCESS);
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
	int i;

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
