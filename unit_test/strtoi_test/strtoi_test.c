/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtoi_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:15:57 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/30 00:03:12 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "cub_strtoi_bonus.h"
#include "unit_test.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 || *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void	test(char *str, long expected_nbr, char *expected_endptr)
{
	char	*endptr;
	long	nbr;

	unit_test(increase_tests);

	nbr = cub_strtoi(str, &endptr);
	printf("test %2i", unit_test(get_tests));
	if ((expected_nbr == nbr) && (ft_strcmp(endptr, expected_endptr) == 0))
	{
		printf(GREEN" [ok] "RESET);	
		printf("input: %30s ", str);
		unit_test(increase_success);
	}
	else
	{
		printf(RED" [ko] "RESET);
		printf("input: %30s ", str);
		printf("expected: "GREEN"%20li "RESET, expected_nbr);
		if (expected_nbr != nbr)
			printf("result: "GREEN"%li"RESET"\n", nbr);
		else
			printf("result: "RED"%li"RESET"\n", nbr);
		if (ft_strcmp(endptr, expected_endptr) != 0)
			printf("endptr : "GREEN"%s"RESET", "RED"%s\n"RESET, expected_endptr, endptr);
	}
	printf("\n");
}

int	main(void)
{
	test("", 0, "\0");
	test("42", 42, "\0");
	test("+42", 42, "\0");
	test("-42", -42, "\0");
	test("   42", 42, "\0");
	test("  +42", 42, "\0");
	test("  -42", -42, "\0");
	test("+ 42", 0, "+ 42");
	test("- 42", 0, "- 42");
	test("+a42", 0, "+a42");
	test("-a42", 0, "-a42");
	test("+42a", 42, "a");
	test("-42a", -42, "a");
	test("2147483646", INT_MAX - 1, "\0");
	test("21474836460", INT_MAX, "0");
	test("2147483647", INT_MAX, "\0");
	test("10000000000", INT_MAX, "0");
	test("1000000000900", INT_MAX, "900");
	test("+2147483647", INT_MAX, "\0");
	test("-2147483648", INT_MIN, "\0");
	test("-10000000000", INT_MIN, "0");
	test("2147483648", INT_MAX, "8");
	test("+2147483648", INT_MAX, "8");
	test("-2147483649", INT_MIN, "9");
	test("-2147483647", INT_MIN + 1, "\0");
	test("21474836470", INT_MAX, "0");
	test("+21474836470", INT_MAX, "0");
	test("-21474836480", INT_MIN, "0");
	test("0000000000000000000000000042", 42, "\0");
	test("-0000000000000000000000000042", -42, "\0");
	test("a42", 0, "a42");
	test("-a42", 0, "-a42");
	test("0a42", 0, "a42");
	test("-0a42", 0, "a42");
	test("-", 0, "-");
	test("+", 0, "+");
	test("++", 0, "++");
	test("+-", 0, "+-");
	test("--", 0, "--");
	test("-+", 0, "-+");
	test("+0", 0, "\0");
	test("-0", 0, "\0");
	test("+0+", 0, "+");
	test("-0-", 0, "-");
	test("+0-", 0, "-");
	test("-0+", 0, "+");
	test("+0000-42", 0, "-42");
	test("-0000+42", 0, "+42");
	test("0000-42", 0, "-42");
	test("0000+42", 0, "+42");
	test("   +a42", 0, "   +a42");
	test("   -a42", 0, "   -a42");
	test("   +42a", 42, "a");
	test("   -42a", -42, "a");
	test("  \t \n", 0, "  \t \n");
	test("  \t \n42", 42, "\0");
	test("  \t \n-42", -42, "\0");
	test("  \t \na42", 0, "  \t \na42");
	test("  \t \n-a42", 0, "  \t \n-a42");
	test("  \t \n0a42", 0, "a42");
	test("  \t \n-0a42", 0, "a42");
	test("  \t \n2147483647", INT_MAX, "\0");
	test("  \t \n-2147483648", INT_MIN, "\0");
	test("  \t \n000000000002147483647", INT_MAX, "\0");
	test("  \t \n-000000000002147483648", INT_MIN, "\0");
	test("  \t \n2147483648", INT_MAX, "8");
	test("  \t \n-2147483649", INT_MIN, "9");
	test("  \t \n-2147483647", INT_MIN + 1, "\0");
	test("  \t \n0000000000000000000000000042", 42, "\0");
	test("  \t \n-0000000000000000000000000042", -42, "\0");
	test("  \t \n00000000000000000000000000a42", 0, "a42");
	test("  \t \n-00000000000000000000000000a42", 0, "a42");
	unit_test_print_result("strtoi", 10);
}