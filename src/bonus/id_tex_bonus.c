/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_tex_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:53:21 by aska              #+#    #+#             */
/*   Updated: 2024/12/10 18:46:20 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "id_tex_bonus.h"

int	get_index_by_key(char *key)
{
	if (key[0] == 'W' && ft_isdigit(key[1]))
		return (key[1] - 48);
	else if (*key == 'F')
		return (0);
	else if (*key == 'C')
		return (10);
	else if (*key == 'R')
		return (11);
	else if (*key == 'T')
		return (12);
	else if (*key == 'L')
		return (13);
	else
		return (FAIL);
}