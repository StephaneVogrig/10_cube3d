/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:33:04 by aska              #+#    #+#             */
/*   Updated: 2024/09/11 15:53:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_organizer(t_cub *cub, char *file)
{
	int ok;
	
	ok = open_cub(cub, file);
	if (chk_box(ok, EQ, SUCCESS, file) == 1)
		helltrain(cub, ERROR, 1, file);
	ok = asset_discovery(cub);
	if (chk_box(ok, EQ, SUCCESS, "Asset discover on .cub") == 1)
		helltrain(cub, ERROR, 1, "asset_discovery");
	ok = init_map_process(cub);
	if (chk_box(ok, EQ, SUCCESS, "Initialize Map") == 1)
		helltrain(cub, ERROR, 1, "Error on Initialization Map");
	ok = set_var_creation_map(cub);
	if (chk_box(ok, EQ, SUCCESS, "Setting Map Variables") == 1)
		helltrain(cub, ERROR, 1, "Error on Allocation Map");
	ok = map_creation(cub);
	if (chk_box(ok, EQ, SUCCESS, "Creating Map") == 1)
		helltrain(cub, ERROR, 1, "Error on Initialization Map");
	ok = map_checker(cub);
	if (chk_box(ok, EQ, SUCCESS, "Check Map") == 1)
		helltrain(cub, ERROR, 1, "Error on Initialization Map");
	// ok = mlx_initialize(cub);
	// if (cub->mlx == NULL)
	// 	helltrain(cub, ERROR, 1, "mlx_init");
}
