/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:14:09 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/08 00:54:40 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_BONUS_H
# define INTERFACE_BONUS_H

# include "interface_utils_bonus.h"
# include "draw_img_interface.h"

int		interface_setup(t_interface	*minimap, void *mlx, t_window *win, t_map *map);
void	interface_destroy(t_interface *minimap);

#endif
