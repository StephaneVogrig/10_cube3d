/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 03:06:27 by aska              #+#    #+#             */
/*   Updated: 2024/09/25 17:28:42 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
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

	i = 0;
	while (line[i] != '\n')
	{
		if (ft_isthis(line[i], " 012NSEW") == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

// void    get_max_map_size(t_cub *cube)
// {
//     t_lstmap    *tmp;
//     int         x;
//     int         y;

//     tmp = cube->map;
//     y = 0;
//     x = 0;
//     while (tmp != NULL)
//     {
//         if (x < (int)ft_strlen(tmp->line))
//             x = ft_strlen(tmp->line);
//         tmp = tmp->next;
//         y++;
//     }
//     cube->map_max_x = x;
//     cube->map_max_y = y;
// }

char	get_blok_type(t_cub *cube, char c, int x, int y)
{
	if (x == cube->map_max_x)
		return ('\0');
	else if (c == '1')
		return (BLOK);
	else if (c == '0')
		return (FLOOR);
	else if (ft_isthis(c, "NSEW") == TRUE)
	{
		cube->player_x = x;
		cube->player_y = y;
		return (c);
	}
	else
		return (MEDIUM_BLOK);
}