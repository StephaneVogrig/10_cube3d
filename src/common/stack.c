/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:01:49 by aska              #+#    #+#             */
/*   Updated: 2025/02/03 17:19:00 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		printf("stack[%d]: x: %d, y: %d\n", i, stack->data[i].x,
			stack->data[i].y);
		i++;
	}
}

t_status	create_stack(int capacity, t_stack *stack)
{
	stack->capacity = capacity;
	stack->top = 0;
	stack->data = malloc(stack->capacity * sizeof(*(stack->data)));
	if (stack->data == NULL)
		return (ft_return(ERROR, FAIL, "create_stack", "malloc fail"));
	return (SUCCESS);
}

t_status	push(t_stack *stack, t_cell cell)
{
	if (stack->top == stack->capacity - 1)
		return (ft_return(ERROR, FAIL, "push", "stack overflow"));
	stack->data[++stack->top] = cell;
	return (SUCCESS);
}

t_cell	pop(t_stack *stack)
{
	return (stack->data[stack->top--]);
}

int	is_stack_empty(t_stack *stack)
{
	if (stack->top == 0)
		return (TRUE);
	return (FALSE);
}
