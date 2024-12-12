/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:18:51 by aska              #+#    #+#             */
/*   Updated: 2024/12/12 21:37:27 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_setup_bonus.h"

int	mlx_setup(t_window *win, t_tex_path *tex_path, t_asset *textures)
{
	int exit_code;
	void *mlx;
	int i;

	i = -1;
	mlx = mlx_init();
	if (mlx == NULL)
		return (ft_return(ERROR, 258, "Error on mlx_init"));
	while (i++ < 13)
	{
		if (tex_path->path[i] == NULL)
			continue ;
		exit_code = texture_load_to_buffer(mlx, &textures->tex[i],
				tex_path->path[i]);
		if (exit_code != SUCCESS)
			return (exit_code);
		tex_path->path[i] = ft_char_f(tex_path->path[i]);
	}
	if (exit_code == SUCCESS)
		exit_code = window_setup(win, mlx);
	return (exit_code);
}
