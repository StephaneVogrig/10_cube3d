/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:12:46 by aska              #+#    #+#             */
/*   Updated: 2024/09/29 09:44:46 by aska             ###   ########.fr       */
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