/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 02:56:33 by aska              #+#    #+#             */
/*   Updated: 2024/08/02 14:59:43 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../libft.h"

int	valid(char *check_msg)
{
	ft_printf(HYEL "  [✅]\t: %s\n" CRESET, check_msg);
	return (0);
}

int	no_valid(char *check_msg)
{
	ft_printf(HYEL "  [❌]\t: %s\n" CRESET, check_msg);
	return (1);
}

int chk_box_le_ge(int test, int if_valid, char *check_msg, int inv)
{
	if (inv == 0)
	{
		if (test <= if_valid && DEBUG_MODE >= 2)
			return(valid(check_msg));
		else if (test > if_valid && DEBUG_MODE >= 2)
			return(no_valid(check_msg));
	}
	else if (inv == 1)
	{
		if (test >= if_valid && DEBUG_MODE >= 2)
			return(valid(check_msg));
		else if (test < if_valid && DEBUG_MODE >= 2)
			return(no_valid(check_msg));
	}
	return(test);
}

int chk_box_lt_gt(int test, int if_valid, char *check_msg, int inv)
{
	if (inv == 0)
	{
		if (test < if_valid && DEBUG_MODE >= 2)
			return(valid(check_msg));
		else if (test >= if_valid && DEBUG_MODE >= 2)
			return(no_valid(check_msg));
	}
	else if (inv == 1)
	{
		if (test > if_valid && DEBUG_MODE >= 2)
			return(valid(check_msg));
		else if (test <= if_valid && DEBUG_MODE >= 2)
			return(no_valid(check_msg));
	}
	return(test);
}

int	chk_box_eq(int test, int if_valid, char *check_msg, int inv)
{
	if (inv == 0)
	{
		if (test == if_valid && DEBUG_MODE >= 2)
			return(valid(check_msg));
		else if (test != if_valid && DEBUG_MODE >= 2)
			return(no_valid(check_msg));
	}
	else if (inv == 1)
	{
		if (test != if_valid && DEBUG_MODE >= 2)
			return(valid(check_msg));
		else if (test == if_valid && DEBUG_MODE >= 2)
			return(no_valid(check_msg));
	}
	return(test);
}
