/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:05:01 by aska              #+#    #+#             */
/*   Updated: 2025/02/04 13:39:08 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_bonus.h"

inline
t_bool	next_valid_asset(t_lstmap **tmp, int *exit_code)
{
	while (*tmp != NULL && is_empty((*tmp)->line) == TRUE)
		*tmp = (*tmp)->next;
	if (*tmp == NULL)
	{
		*exit_code = FAIL;
		return (ft_return(ERROR, FALSE, "End of file", "missing data"));
	}
	if (!ft_isthis((*tmp)->line[0], "NWESFCTLR"))
		return (FALSE);
	if (!ft_isthis((*tmp)->line[1], "EAOP \f\r\t\v123456789"))
		return (FALSE);
	if (ft_isspace((*tmp)->line[1]) == FALSE)
		if (ft_isspace((*tmp)->line[2]) == FALSE)
			return (FALSE);
	return (TRUE);
}

inline
void	next_line_not_empty(t_lstmap **tmp)
{
	if (*tmp == NULL)
		return ;
	*tmp = (*tmp)->next;
	while (*tmp != NULL && is_empty((*tmp)->line) == TRUE)
		*tmp = (*tmp)->next;
}
