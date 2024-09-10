/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:01:25 by aska              #+#    #+#             */
/*   Updated: 2024/09/10 23:14:21 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../include/cub3d.h"

int	map_checker(t_cub *cub)
{
	cub->err = set_var_creation_map_ff(cub);
	if (chk_box(cub->err, EQ, SUCCESS, "Creating flood fill Map") == 1)
		helltrain(cub, ERROR, 1, "Error on Initialization Map");
	chk_flood_fill(cub, cub->player_x, cub->player_y);
	chk_box(0, EQ, SUCCESS, "Flood Fill");
    ft_tab_f(cub->map_ff);
	return (SUCCESS);
}

int	set_var_creation_map_ff(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	cub->map_ff = ft_calloc(cub->map_max_y + 3, sizeof(char *));
	if (cub->map_ff == NULL)
		return (ERROR);
	while (y != cub->map_max_y + 2)
	{
		cub->map_ff[y] = ft_calloc(cub->map_max_x + 3, sizeof(char));
		if (cub->map_ff[y] == NULL)
			return (ERROR);
		if (y != 0 && y != cub->map_max_y + 1)
		{
			x = 1;
			while (x != cub->map_max_x + 1)
			{
				cub->map_ff[y][x] = cub->map_tab[y - 1][x - 1];
				x++;
			}
		}
		y++;
	}
	return (SUCCESS);
}

void	chk_flood_fill(t_cub *cub, int x, int y)
{
	if (cub->map_ff[y][x] == BLOK || cub->map_ff[y][x] == 'X')
		return ;
	if (cub->map_ff[y][x] == 0)
		helltrain(cub, ERROR, 1, "Map Invalid");
	cub->map_ff[y][x] = 'X';
	chk_flood_fill(cub, x + 1, y);
	chk_flood_fill(cub, x - 1, y);
	chk_flood_fill(cub, x, y + 1);
	chk_flood_fill(cub, x, y - 1);
}