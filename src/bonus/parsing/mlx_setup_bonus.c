/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:18:51 by aska              #+#    #+#             */
/*   Updated: 2025/01/30 01:45:33 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_bonus.h"
#include "mlx_setup_bonus.h"
#include "pointer_table_bonus.h"

int	mlx_setup(t_window *win, t_asset *textures, t_asset_lst **head)
{
	int		exit_code;
	void	*mlx;

	mlx = mlx_init();
	if (mlx == NULL)
		return (ft_return(ERROR, FAIL, "Error on mlx_init", NULL));
	exit_code = asset_lst_to_array(mlx, textures, *head);
	if (exit_code == SUCCESS)
		pointer_table_init(textures);
	if (exit_code == SUCCESS)
		exit_code = window_setup(win, mlx);
	return (exit_code);
}
