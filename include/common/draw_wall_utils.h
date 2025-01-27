/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:08:37 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:04:32 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_WALL_UTILS_H
# define DRAW_WALL_UTILS_H

# include "ray.h"
# include "vector.h"
# include "window.h"

int	hitpos_wall_texture(int texture_width, t_ray *ray);

#endif