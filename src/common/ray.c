/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:32:37 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/23 00:42:32 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ray.h"

int	ray_setup(t_ray_tab *rays, int nbr)
{
	rays->tab = malloc(nbr * sizeof(*rays->tab));
	if (rays->tab == NULL)
	{
		printf("ray_setup: malloc fail\n");
		return (FAIL);
	}
	rays->nbr = nbr;
	return (SUCCESS);
}

void	ray_destroy(t_ray_tab *rays)
{
	if (rays->tab)
		free(rays->tab);
}
