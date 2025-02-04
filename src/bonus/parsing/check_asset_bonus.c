/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:52:34 by aska              #+#    #+#             */
/*   Updated: 2025/02/04 22:43:40 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_asset_bonus.h"

static bool	is_save_cell(char cell)
{
	static char	save[NBR_KEY_IN_GRID] = {0};
	int			i;

	i = 0;
	while (save[i] != '\0')
	{
		if (save[i] == cell)
			return (true);
		i++;
	}
	save[i] = cell;
	return (false);
}

int	cmp_cell_line_to_asset_key(char *line, t_asset_lst *asset_lst)
{
	int	i;

	if (key_is_in_asset_lst(asset_lst, "F") == FALSE)
		return (ft_return(ERROR, FAIL, "Missing floor asset", line));
	if (key_is_in_asset_lst(asset_lst, "C") == FALSE)
		return (ft_return(ERROR, FAIL, "Missing ceil asset", line));
	i = -1;
	while (line[++i] != '\0')
	{
		if (ft_isthis(line[i], " 0NSEW") || is_save_cell(line[i]) == true)
			continue ;
		if (asset_lst_key_exist(asset_lst, line[i]) == FALSE)
			return (ft_return(ERROR, FAIL, "Invalid or missing Asset Key",
					line));
	}
	return (SUCCESS);
}
