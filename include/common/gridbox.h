/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gridbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:55:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/04 19:40:29 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GRIDBOX_H
# define GRIDBOX_H

typedef struct s_gridbox
{
	int		grid;
	float	box;
}	t_gridbox;

void	gridbox_add_double(t_gridbox	*gb, double d);

#endif
