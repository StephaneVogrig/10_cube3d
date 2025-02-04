/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:06:21 by aska              #+#    #+#             */
/*   Updated: 2025/02/04 19:47:02 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_value.h"

static inline int	setup_key_value_separate_by_space(char **key, char **value,
		char *line)
{
	*key = line;
	while (*line != '\0' && ft_isspace(*line) == FALSE)
		line++;
	if (*line == '\0')
		return (ft_return(ERROR, FAIL, "Invalid Key", line));
	*line = '\0';
	line++;
	while (ft_isspace(*line) == TRUE)
		line++;
	if (*line == '\0')
		return (ft_return(ERROR, FAIL, "Invalid Value", line));
	*value = line;
	return (SUCCESS);
}

t_status	set_key_value(t_key_value *kv, char *line)
{
	if (line == NULL || kv == NULL)
		return (FAIL);
	if (setup_key_value_separate_by_space(&(kv->key), &(kv->value),
			line) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}
