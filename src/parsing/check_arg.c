/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:12:46 by aska              #+#    #+#             */
/*   Updated: 2024/10/08 03:01:45 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "check_arg.h"

int	check_entry_arg(int ac, char **av)
{
	if (chk_box(ac, EQ, 2, NUM_OF_ARG) != SUCCESS)
		return (ft_return(ERROR, FAIL, INVALID_NUM_OF_ARG));
	if ((ft_strnstr(av[1], EXTENSION_FILE, ft_strlen(av[1]))) == NULL)
	{
		chk_box(1, EQ, 0, TITLE_FILE_EXT);
		return (ft_return(ERROR, FAIL, NO_CUB_EXT));
	}
	else
		chk_box(0, EQ, 0, TITLE_FILE_EXT);
	return (OK);
}

int	check_arg_color(char **rgb)
{
	int	i;
	int	j;
	int	rgb_len;
	int	rgb_i;

	i = 0;
	while (rgb[i])
	{
		rgb_len = ft_strlen(rgb[i]);
		if (rgb_len > 10)
			return (FAIL);
		j = 0;
		while (rgb[i][j])
			if (ft_isdigit(rgb[i][j++] == 0))
				return (FAIL);
		rgb_i = ft_atoi(rgb[i]);
		if (rgb_len != ft_intlen(rgb_i, 0))
			return (FAIL);
		if (rgb_i < 0 || rgb_i > 255)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}