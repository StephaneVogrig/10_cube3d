/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordonate_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:48:01 by aska              #+#    #+#             */
/*   Updated: 2025/02/05 22:18:47 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDONATE_BONUS_H
# define COORDONATE_BONUS_H

# include "libft.h"
# include "lstmap.h"
# include "lstmap_bonus.h"
# include "sprite_bonus.h"
# include "sprite_lst_bonus.h"
# include "cub_strtoi.h"
# include "parsing_utils.h"
# include <math.h>

typedef struct s_build_double
{
	int		integer;
	int		decimal;
	double	result;
}	t_build_double;

int	extract_coordonate_sprite(t_sprite_lst **sprite_lst, t_lstmap **tmp,
		int id);
int	set_sprite_coordonate(char *line, t_sprite_lst **head, int id);

#endif