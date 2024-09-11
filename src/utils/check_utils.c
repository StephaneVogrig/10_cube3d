/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:12:46 by aska              #+#    #+#             */
/*   Updated: 2024/09/11 17:09:57 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void entry_arg_checker(int ac, char **av)
{
    int strnstr;

    strnstr = 0;
    if (chk_box(ac, EQ, 2, "Number of entry arguments") != SUCCESS)
        ft_exit(ERROR,ERROR, "Invalid number of parameters");
    if ((ft_strnstr(av[1], ".cub", ft_strlen(av[1]))) == NULL)
        strnstr = 1;
    if (chk_box(strnstr, EQ, 0, "File extension") != SUCCESS)
        ft_exit(ERROR,ERROR, "No \".cub\" extension map file");
}
