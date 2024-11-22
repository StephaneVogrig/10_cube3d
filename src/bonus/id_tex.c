/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_tex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:53:21 by aska              #+#    #+#             */
/*   Updated: 2024/11/22 17:58:44 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "id_tex.h"

int	get_index_by_key(char *key)
{
	if (ft_isdigit(key[0]))
		return (key[0] - 48);
	else if (key[0] == 'F')
		return (0);
	else if (key[0] == 'C')
		return (10);
	else if (key[0] == 'R')
		return (11);
	else if (key[0] == 'T')
		return (12);
	else if (key[0] == 'L')
		return (13);
	else
		return (FAIL);
}