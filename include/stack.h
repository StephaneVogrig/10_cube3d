/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:57:27 by aska              #+#    #+#             */
/*   Updated: 2024/10/30 13:21:28 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_cell
{
	int				x;
	int				y;
}					t_cell;

typedef struct s_stack
{
	t_cell			*data;
	int				top;
	int	capacity;
}					t_stack;

t_stack				*create_stack(int capacity, t_stack *stack);
t_status			push(t_stack *stack, t_cell cell);
t_cell				pop(t_stack *stack);
int					is_stack_empty(t_stack *stack);
