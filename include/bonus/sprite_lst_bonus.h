/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_lst_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:08:16 by aska              #+#    #+#             */
/*   Updated: 2024/12/19 18:58:02 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_LST_BONUS_H
# define SPRITE_LST_BONUS_H

# include "libft.h"
typedef struct s_sprite_lst
{
	int					id;
	double				x;
	double				y;
	struct s_sprite_lst	*next;
	struct s_sprite_lst	*prev;
}						t_sprite_lst;

t_sprite_lst	*insert_sprite_lst(t_sprite_lst **head, double x,double y, int id);
void			delete_node_sprite(t_sprite_lst **head, t_sprite_lst *del_node);
void			delete_all_sprite(t_sprite_lst **head);
void	print_sprite_lst(t_sprite_lst *head);

#endif