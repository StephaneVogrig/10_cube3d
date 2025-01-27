/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_manda.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:52:20 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:17:57 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_MANDA_H
# define DDA_MANDA_H

# include "data_manda.h"
# include "dda_utils.h"
# include "map.h"
# include "player.h"
# include "ray.h"

void	dda(t_ray *ray, t_position *start, t_data *data);

#endif