/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixedpoint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:55:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 16:48:29 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FIXEDPOINT_H
# define FIXEDPOINT_H

typedef struct s_fixedpoint
{
	int		grid;
	float	box;
}	t_fixedpoint;

void	fixedpoint_add_double(t_fixedpoint	*gb, double d);
void	fixedpoint_add_fixedpoint(t_fixedpoint *a, t_fixedpoint *b);

#endif
