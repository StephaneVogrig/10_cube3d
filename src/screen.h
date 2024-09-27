/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:36:49 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/27 16:44:12 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "../lib/MacroLibx/includes/mlx.h"
# include "../lib/libft-plus/libft.h"
# include "typedef.h"

typedef struct s_screen
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;
}			t_screen;

int			screen_init(t_screen *screen, void *mlx, int width, int height);

#endif