/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 02:56:33 by aska              #+#    #+#             */
/*   Updated: 2025/01/30 17:43:32 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	chk_box(int test, t_condition selector, int if_valid, char *check_msg)
{
	if (selector == EQ)
		return (chk_box_eq(test, if_valid, check_msg, 0));
	else if (selector == NE)
		return (chk_box_eq(test, if_valid, check_msg, 1));
	else if (selector == LT)
		return (chk_box_lt_gt(test, if_valid, check_msg, 0));
	else if (selector == GT)
		return (chk_box_lt_gt(test, if_valid, check_msg, 1));
	else if (selector == LE)
		return (chk_box_le_ge(test, if_valid, check_msg, 0));
	else if (selector == GE)
		return (chk_box_le_ge(test, if_valid, check_msg, 1));
	else
		return (ft_return(WARNING, test, "Invalid selector", check_msg));
}
