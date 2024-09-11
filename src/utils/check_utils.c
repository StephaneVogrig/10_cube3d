/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:12:46 by aska              #+#    #+#             */
/*   Updated: 2024/09/11 14:38:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void entry_arg_checker(int ac, char **av)
{
    int err;
    int strnstr;

    err = 0;
    strnstr = 0;
    err = chk_box(ac, EQ, 2, "Number of entry arguments");
    goto_exit(err, err, ERROR, "No Parameter");
    if ((ft_strnstr(av[1], ".cub", ft_strlen(av[1]))) == NULL)
        strnstr = 1;
    err = chk_box(strnstr, EQ, 0, "Check file extension");
    goto_exit(err, err, ERROR, EXTENSION_ERROR);
}