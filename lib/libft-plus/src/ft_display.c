/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:40:12 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/07/09 16:26:11 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../libft.h"

void	ft_display(t_state state,char *add_msg)
{
	if (DEBUG_MODE >= 2)
    {
        if (state == INFO)
            ft_putstr_fd(BCYN "INFO" CRESET, 1);
        else if (state == WARNING)
            ft_putstr_fd(BYEL "WARNING" CRESET, 1);
        else if (state == ERROR)
            ft_putstr_fd(BRED "ERROR" CRESET, 2);
    }
	else if (DEBUG_MODE == 1 && state == ERROR)
		ft_putstr_fd("Error\n", 2);
	if (add_msg != NULL && DEBUG_MODE > 0)
	{
		if (DEBUG_MODE >= 2)
			ft_putstr_fd("\t: ", 2);
        if (state == PERROR)
		    perror(add_msg);
        else
        {
            ft_putstr_fd(add_msg, 1);
            ft_putstr_fd("\n", 1);
        }
	}
}
