/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:52:34 by aska              #+#    #+#             */
/*   Updated: 2024/12/30 04:50:10 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_asset_bonus.h"

char chk_save_cell(char cell)
{
    static char save[13] = {0};
    int i;

    i = 0;
    while (save[i] != '\0')
    {
        if (save[i] == cell)
            return ('\0');
        i++;
    }
    save[i] = cell;
    return (cell);
}

int cmp_cell_line_to_asset_key(char *line, t_asset_lst *asset_lst)
{
    int i;

    i = -1;
    while (line[++i] != '\0')
    {
        if (ft_isthis(line[i], " NSEW") == TRUE || chk_save_cell(line[i]) == '\0')
            continue;
        if (asset_lst_key_exist(asset_lst, line[i]) == FALSE)
            return (ft_return(ERROR, FAIL, "L.41:cmp_cell_line_to_asset_key: Key not found"));
    }
    return (SUCCESS);
}