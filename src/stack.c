/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:01:49 by aska              #+#    #+#             */
/*   Updated: 2024/10/29 23:39:49 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack *create_stack(int capacity, t_stack *stack)
{
	stack->capacity = capacity;
	stack->top = -1;
	stack->data = (t_cell *)malloc(stack->capacity * sizeof(t_cell));
	return (stack);
}

t_status push(t_stack *stack, t_cell cell)
{
	if (stack->top == stack->capacity - 1)
	{
		printf("Stack Overflow\n");
		return (FAIL);
	}
	stack->data[++stack->top] = cell;
    return (SUCCESS);
}

t_cell pop(t_stack *stack)
{
    if (stack->top == 0)
    {
        printf("Stack Underflow\n");
        return ((t_cell){0, 0});
    }
    return (stack->data[stack->top--]);
}
