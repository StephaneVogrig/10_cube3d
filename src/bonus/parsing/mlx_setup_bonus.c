/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:18:51 by aska              #+#    #+#             */
/*   Updated: 2024/12/22 14:07:34 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_setup_bonus.h"
#include "asset_bonus.h"
#include "pointer_table_bonus.h"
#include "option_bonus.h"

int	mlx_setup(t_window *win, t_asset *textures, t_asset_lst **head)
{
	int exit_code;
	void *mlx;
	t_option 	*option;

	option = option_get_ptr();
	mlx = mlx_init();
	if (mlx == NULL)
		return (ft_return(ERROR, 258, "Error on mlx_init"));
	exit_code = asset_lst_to_array(mlx, textures, *head);
	if (exit_code == SUCCESS)
		pointer_table_init(textures);
	win->height = option->win_height;
	win->width = option->win_width;
	if (exit_code == SUCCESS)
		exit_code = window_setup(win, mlx);
	return (exit_code);
}
