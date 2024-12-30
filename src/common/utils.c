/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:30:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/30 15:31:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "utils.h"

char	choose_side(t_bool test, char val_if_true, char val_if_false)
{
	if (test == TRUE)
		return (val_if_true);
	return (val_if_false);
}
