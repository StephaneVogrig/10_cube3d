/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:52:01 by aska              #+#    #+#             */
/*   Updated: 2025/02/03 15:36:57 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

inline
char	*spacetrim(char *str)
{
	char	*trim_str;
	int		end_str;

	while (ft_isspace(*str))
		str++;
	trim_str = str;
	end_str = ft_strlen_endc(trim_str, '\0');
	while (end_str > 0 && ft_isspace(trim_str[end_str - 1]))
		end_str--;
	trim_str[end_str] = '\0';
	return (trim_str);
}

void	skip_blank(char **str)
{
	if (!str)
		return ;
	while (ft_isspace(**str))
		(*str)++;
}

int	is_empty(char *str)
{
	while (*str)
		if (ft_isspace(*str++) == FALSE)
			return (FALSE);
	return (TRUE);
}

int	is_map_valid(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isthis(line[i], " 01NSEW\n") == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
