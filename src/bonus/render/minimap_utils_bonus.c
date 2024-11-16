/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:36:54 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/15 16:42:45 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minimap_utils_bonus.h"

t_minimap	*minimap_get_ptr(void)
{
	static t_minimap minimap;

	return (&minimap);
}
