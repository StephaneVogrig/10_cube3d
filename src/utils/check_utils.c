/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:12:46 by aska              #+#    #+#             */
/*   Updated: 2024/09/11 17:28:49 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void check_entry_arg(int ac, char **av)
{
    if (chk_box(ac, EQ, 2, "Number of entry arguments") != SUCCESS)
        ft_exit(ERROR,ERROR, "Invalid number of parameters");
    if ((ft_strnstr(av[1], ".cub", ft_strlen(av[1]))) == NULL)
    {
        chk_box(1, EQ, 0, "File extension");
        ft_exit(ERROR,ERROR, "No \".cub\" extension map file");
    }
    else
        chk_box(0, EQ, 0, "File extension");
}
