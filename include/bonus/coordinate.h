/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:48:01 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 16:04:04 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATE_H
# define COORDINATE_H

# include "libft.h"
# include "lstmap.h"
# include "sprite_bonus.h"
# include "sprite_lst_bonus.h"

int	set_sprite_coordinate(char *line, t_sprite_lst **head, int id);

#endif