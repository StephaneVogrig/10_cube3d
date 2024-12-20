/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:48:01 by aska              #+#    #+#             */
/*   Updated: 2024/12/20 21:43:03 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef COORDINATE_H
# define COORDINATE_H

#include "lstmap.h"
#include "libft.h"
#include "sprite_bonus.h"
#include "sprite_lst_bonus.h"

int set_sprite_coordinate(char *line, t_sprite_lst **head, int id);

#endif