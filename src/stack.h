/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:57:27 by aska              #+#    #+#             */
/*   Updated: 2024/10/30 03:36:48 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_cell
{
	unsigned int	x;
	unsigned int	y;
}					t_cell;

typedef struct s_stack
{
	t_cell			*data;
	unsigned int	top;
	unsigned int	capacity;
}					t_stack;

t_stack				*create_stack(int capacity, t_stack *stack);
t_status			push(t_stack *stack, t_cell cell);
t_cell				pop(t_stack *stack);
int					is_stack_empty(t_stack *stack);
