/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:05:01 by aska              #+#    #+#             */
/*   Updated: 2025/01/31 21:10:01 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_bonus.h"

void next_line_not_empty(t_lstmap **tmp)
{
	if (*tmp == NULL)
		return ;
	*tmp = (*tmp)->next;
	while (*tmp != NULL && is_empty((*tmp)->line) == TRUE)
		*tmp = (*tmp)->next;
}