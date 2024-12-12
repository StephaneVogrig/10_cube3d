/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:47:44 by aska              #+#    #+#             */
/*   Updated: 2024/12/12 16:54:10 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinate.h"


static float custom_atof(char *str)
{
	float	integer;
	float	decimal;
	int		sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str != '.' && *str != ',' && *str != '\0')
		str++;
	if (*str == '\0')
		return ((float)ft_atoi(str));
	*str = '\0';
	integer = ft_atoi(str);
	while (*str != '.' && *str != ',' && *str != '\0')
		str++;
	*str = '\0';
	decimal = ft_atoi(str);
	return (sign * (integer + decimal / ft_intlen(decimal,0)));
}

static int extract_raw_coordinate(char *line, char **x, char **y)
{
	line++;
	*x = line;
	while (*line != ';' && *line != '\0')
	{
		if (ft_isthis(*line, "-0123456789.,") == FALSE)
			return (FAIL);
		line++;
	}
	*line = '\0';
	line++;
	*y = line;
	while (*line != ']' && *line != '\0')
	{
		if (ft_isthis(*line, "-0123456789.,") == FALSE)
			return (FAIL);
		line++;
	}
	return (SUCCESS);
}

int set_sprite_coordinate(char *line)
{
	char *x;
	char *y;
	float x_f;
	float y_f;

	extract_raw_coordinate(line, &x, &y);
	x_f = custom_atof(x);
	y_f = custom_atof(y);
	printf("x: %f, y: %f\n", x_f, y_f);
	return (SUCCESS);
}