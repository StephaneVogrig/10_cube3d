/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:10:46 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/29 23:55:25 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	unit_test_print_result(const char *title, int field_width)
{
	printf("%-*s ", field_width, title);
	printf("%3i / ", unit_test(get_success));
	printf("%3i tests passed\n", unit_test(get_tests));
}

int	unit_test(t_action action)
{
	static int	tests;
	static int	success;

	if (action == init)
	{
		tests = 0;
		success = 0;
	}
	if (action == increase_tests)
		return (tests++);
	if (action == increase_success)
		return (success++);
	if (action == get_tests)
		return (tests);
	if (action == get_success)
		return (success);
	return (0);
}
