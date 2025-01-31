/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:53:38 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/31 17:16:32 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	color_darkened(int color, int dark)
{
	if (dark)
		return ((color >> 2) & 0xFF3F3F3F);
	return (color);
}

static int	char_to_rgb(char *value, char **endptr, unsigned char *rgb)
{
	int	c;

	c = cub_strtoi(value, endptr);
	if (value == *endptr || c < 0 || c > 255)
		return (FAIL);
	*rgb = (unsigned char)c;
	skip_blank(endptr);
	if (**endptr == '\0' || **endptr == ',')
		return (SUCCESS);
	else
		return (FAIL);
	return (SUCCESS);
}

int	color_set_rgb(t_rgb *rgb, char *value)
{
	int		exit_code;
	char	*current;
	char	*endptr;

	current = value;
	endptr = NULL;
	exit_code = char_to_rgb(current, &endptr, &rgb->r);
	if (exit_code == FAIL || *endptr == '\0')
		return (ft_return(ERROR, FAIL, "Invalid color", value));
	current = endptr + 1;
	exit_code = char_to_rgb(current, &endptr, &rgb->g);
	if (exit_code == FAIL || *endptr == '\0')
		return (ft_return(ERROR, FAIL, "Invalid color", value));
	current = endptr + 1;
	exit_code = char_to_rgb(current, &endptr, &rgb->b);
	if (exit_code == FAIL || *endptr != '\0')
		return (ft_return(ERROR, FAIL, "Invalid color", value));
	rgb->a = 255;
	return (SUCCESS);
}

// int color_set_rgb_2(t_rgb *rgb, char *str)
// {
// 	char *current;
// 	char *endptr;

// 	rgb->a = 255;

// 	current = str;
// 	rgb->r = cub_strtoi(current, &endptr);
// 	if (current == endptr || rgb->r < 0 || rgb->r >255)
// 		return (ft_return(ERROR, FAIL, "Invalid color red", str));

// 	current = endptr;
// 	skip_blank(&current);
// 	if (*current != '.' && *current != ',')
// 		return (ft_return(ERROR, FAIL, "Invalid color", str));
// 	current++;

// 	rgb->g = cub_strtoi(current, &endptr);
// 	if (current == endptr || rgb->g < 0 || rgb->g >255)
// 		return (ft_return(ERROR, FAIL, "Invalid color red", str));

// 	current = endptr;
// 	skip_blank(&current);
// 	if (*current != '.' && *current != ',')
// 		return (ft_return(ERROR, FAIL, "Invalid color", str));
// 	current++;

// 	rgb->b = cub_strtoi(current, &endptr);
// 	if (current == endptr || rgb->b < 0 || rgb->b >255)
// 		return (ft_return(ERROR, FAIL, "Invalid color red", str));

// 	skip_blank(&endptr);
// 	if (*endptr != '\0')
// 		return (ft_return(ERROR, FAIL, "Invalid color red", str));
// 	return (SUCCESS);
// }
