/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manda.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:13:53 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:04:52 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_MANDA_H
# define RAYCASTING_MANDA_H

# include "data_manda.h"
# include "dda_manda.h"
# include "player.h"
# include "ray.h"
# include "vector.h"

void	raycasting(t_ray *rays, t_data *data);

#endif
