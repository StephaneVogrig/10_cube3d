/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:12:46 by aska              #+#    #+#             */
/*   Updated: 2024/09/26 15:33:22 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

int	check_entry_arg(int ac, char **av)
{
	if (chk_box(ac, EQ, 2, "Number of entry arguments") != SUCCESS)
		return (ft_return(ERROR, FAIL, "Invalid number of arguments"));
	if ((ft_strnstr(av[1], ".cub", ft_strlen(av[1]))) == NULL)
	{
		chk_box(1, EQ, 0, "File extension");
		return (ft_return(ERROR, FAIL, "No \".cub\" extension map file"));
	}
	else
		chk_box(0, EQ, 0, "File extension");
	return (OK);
}