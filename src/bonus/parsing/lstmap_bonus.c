/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:05:01 by aska              #+#    #+#             */
/*   Updated: 2025/02/01 17:37:06 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_bonus.h"

inline
t_bool	next_valid_asset(t_lstmap **tmp)
{
	while (*tmp != NULL && is_empty((*tmp)->line) == TRUE)
		*tmp = (*tmp)->next;
	if (*tmp == NULL)
		return (FALSE);
	if (!ft_isthis((*tmp)->line[0], "NWESFCTLR"))
		return (FALSE);
	if (!ft_isthis((*tmp)->line[1], "EAOP \t123456789"))
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
