/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_key_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:05:15 by aska              #+#    #+#             */
/*   Updated: 2025/01/30 17:43:10 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	setup_key_value(char **key, char **value, char *line, char separator)
{
	*key = line;
	while (*line != 0)
	{
		if (*line == separator)
		{
			*line = '\0';
			line++;
			*value = line;
			return (0);
		}
		line++;
	}
	return (-1);
}
