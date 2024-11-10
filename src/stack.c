/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:01:49 by aska              #+#    #+#             */
/*   Updated: 2024/11/10 18:02:17 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "stack.h"

t_status	create_stack(int capacity, t_stack *stack)
{
	stack->capacity = capacity;
	stack->top = 0;
	stack->data = malloc(stack->capacity * sizeof(*(stack->data)));
	if (stack->data == NULL)
		return (FAIL);
	return (SUCCESS);
}

t_status	push(t_stack *stack, t_cell cell)
{
	if (stack->top == stack->capacity - 1)
	{
		printf("Stack Overflow\n");
		return (FAIL);
	}
	stack->data[++stack->top] = cell;
	return (SUCCESS);
}

t_cell	pop(t_stack *stack)
{
	if (stack->top == 0)
	{
		printf("Stack Underflow\n");
		return ((t_cell){0, 0});
	}
	return (stack->data[stack->top--]);
}

int	is_stack_empty(t_stack *stack)
{
	if (stack->top == 0)
		return (1);
	return (0);
}