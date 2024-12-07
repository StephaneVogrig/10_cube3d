/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fixepoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:15:58 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/04 04:25:05 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/common/gridbox.h"
#include <stdio.h>
#include <limits.h>

# define RESET "\e[0m"

// Regular text
# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define BLUE "\e[0;34m"
# define MAGENTA "\e[0;35m"
# define CYAN "\e[0;36m"
# define WHITE "\e[0;37m"


void	print_gridbox(t_gridbox gridbox, char *color)
{
	printf("grid: %s%3i" RESET " box: %s%10f" RESET, color, gridbox.grid, color, gridbox.box);
}

void test_gridbox_add_double(t_gridbox tested_gb, double tested_d, t_gridbox expected)
{
	t_gridbox	result;
	int				success;
	
	result = tested_gb;
	
	gridbox_add_double(&result, tested_d);
	
	success = (result.grid == expected.grid) && (result.box == expected.box) ;

	printf("   tested   " );
	print_gridbox(tested_gb, YELLOW);
	printf("\n                    value: " YELLOW "%10f" RESET "\n   expected ", tested_d);
	print_gridbox(expected, GREEN);
	
		printf("\n   result   grid: " );
	if (success)
	{
		printf(GREEN "%3i " RESET "box: " GREEN "%10f" RESET, result.grid, result.box);
		printf(" ✅\n\n" RESET);
	}
	else
	{
		if (result.grid == expected.grid)
			printf(GREEN "%3i " RESET, result.grid);
		else
			printf(RED "%3i " RESET, result.grid);
		if (result.box == expected.box)
			printf("box: " GREEN "%10f" RESET, result.box);
		else
			printf("box: " RED "%10f" RESET, result.box);
		printf(" ❌\n\n");
	}
}

int main(void)
{
	printf("test gridbox_add_double ---------------------------\n\n");
	
	test_gridbox_add_double((t_gridbox){0, 0.0}, 0.0, (t_gridbox){0, 0.0});
	test_gridbox_add_double((t_gridbox){0, 0.0}, -0.0, (t_gridbox){0, 0.0});
	test_gridbox_add_double((t_gridbox){0, -0.0}, 0.0, (t_gridbox){0, 0.0});
	test_gridbox_add_double((t_gridbox){0, -0.0}, -0.0, (t_gridbox){0, 0.0});
	test_gridbox_add_double((t_gridbox){0, 0.5}, 0.625, (t_gridbox){1, 0.125});
	test_gridbox_add_double((t_gridbox){0, 0.5}, -0.625, (t_gridbox){-1, 0.875});
	test_gridbox_add_double((t_gridbox){0, 0.125}, -0.125, (t_gridbox){0, 0.0});
	test_gridbox_add_double((t_gridbox){0, -0.125}, -0.125, (t_gridbox){-1, 0.75});
	test_gridbox_add_double((t_gridbox){10, 0.125}, -0.125, (t_gridbox){10, 0.0});
	test_gridbox_add_double((t_gridbox){10, 0.125}, -10.125, (t_gridbox){0, 0.0});
	test_gridbox_add_double((t_gridbox){10, 0.125}, -10.25, (t_gridbox){-1, 0.875});
	test_gridbox_add_double((t_gridbox){10, 0.25}, 10.50, (t_gridbox){20, 0.75});
	test_gridbox_add_double((t_gridbox){INT_MAX, 0.25}, 10.50, (t_gridbox){-2147483639, 0.75});
	test_gridbox_add_double((t_gridbox){INT_MIN, 0.25}, 10.50, (t_gridbox){-2147483638, 0.75});
	test_gridbox_add_double((t_gridbox){INT_MAX, 0.25}, -10.50, (t_gridbox){2147483636, 0.75});
	test_gridbox_add_double((t_gridbox){INT_MIN, 0.25}, -10.50, (t_gridbox){2147483637, 0.75});

	return (0);
}
