/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:57:27 by aska              #+#    #+#             */
/*   Updated: 2024/11/25 19:24:46 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

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

t_status			create_stack(int capacity, t_stack *stack);
t_status			push(t_stack *stack, t_cell cell);
t_cell				pop(t_stack *stack);
int					is_stack_empty(t_stack *stack);
