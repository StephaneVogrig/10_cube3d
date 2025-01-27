/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:05:53 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 16:06:09 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_BONUS_H
# define INTERFACE_BONUS_H

# include "draw_img_interface.h"
# include "interface_utils_bonus.h"

int		interface_setup(t_interface *minimap, void *mlx, t_window *win,
			t_map *map);
void	interface_destroy(t_interface *minimap);

#endif
