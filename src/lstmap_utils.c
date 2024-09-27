/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 03:06:27 by aska              #+#    #+#             */
/*   Updated: 2024/09/27 17:26:10 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "lst_map.h"
#include "map.h"

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
