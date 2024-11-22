/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_tex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:53:21 by aska              #+#    #+#             */
/*   Updated: 2024/11/22 18:05:50 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "id_tex.h"

int	get_index_by_key(char key)
{
	if (ft_isdigit(key))
		return (key - 48);
	else if (key == 'F')
		return (0);
	else if (key == 'C')
		return (10);
	else if (key == 'R')
		return (11);
	else if (key == 'T')
		return (12);
	else if (key == 'L')
		return (13);
	else
		return (FAIL);
}