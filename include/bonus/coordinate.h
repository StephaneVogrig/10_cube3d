/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:48:01 by aska              #+#    #+#             */
/*   Updated: 2025/01/30 12:40:30 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATE_H
# define COORDINATE_H

# include "libft.h"
# include "lstmap.h"
# include "sprite_bonus.h"
# include "sprite_lst_bonus.h"
# include "cub_strtoi.h"

int	extract_coordinate_sprite(t_sprite_lst **sprite_lst, t_lstmap **tmp,
		int id);
int	set_sprite_coordinate(char *line, t_sprite_lst **head, int id);

#endif