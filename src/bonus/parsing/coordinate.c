/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:47:44 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 15:06:37 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinate.h"
#include "math.h"

static double	custom_atof(char *str)
{
	char	*tmp;
	double	integer;
	double	decimal;
	int		sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	tmp = str;
	while (*str != '.' && *str != ',' && *str != '\0')
		str++;
	if (*str == '\0')
		return ((double)ft_atoi(tmp));
	*str = '\0';
	integer = ft_atoi(tmp);
	tmp = ++str;
	while (*str != '.' && *str != ',' && *str != '\0')
		str++;
	*str = '\0';
	decimal = ft_atoi(tmp);
	return (sign * (integer + (decimal / pow(10, ft_intlen(decimal, 0)))));
}

static int	extract_raw_coordinate(char *line, char **x, char **y)
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

int	set_sprite_coordinate(char *line, t_sprite_lst **head, int id)
{
	char	*x;
	char	*y;
	double	x_f;
	double	y_f;

	extract_raw_coordinate(line, &x, &y);
	x_f = custom_atof(x);
	y_f = custom_atof(y);
	insert_sprite_lst(head, x_f, y_f, id);
	return (SUCCESS);
}
