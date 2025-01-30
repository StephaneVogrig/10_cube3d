/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:53:38 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/30 03:18:11 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	color_darkened(int color, int dark)
{
	if (dark)
		return ((color >> 2) & 0xFF3F3F3F);
	return (color);
}

static void	skip_blank(char **str)
{
	if (!str)
		return ;
	while (ft_isspace(**str))
		(*str)++;
}

static int	char_to_rgb(char **value, unsigned char *rgb)
{
	int c;
	
	c = cub_strtoi(*value, value);
	ft_printf("c = %d\n", c);
	if (c < 0 || c > 255)
		return (FAIL);
	*rgb = (unsigned char)c;
	skip_blank(value);
	if (**value == ',')
		(*value)++;
	else if (**value == '\0')
		return (SUCCESS);
	else
		return (FAIL);
	return (SUCCESS);
}

int	color_set_rgb(t_rgb *rgb, char *value)
{
	int	exit_code;
	char *tmp_value;

	tmp_value = value;

	exit_code = char_to_rgb(&value, &rgb->r);
	ft_printf("c on return = %d\n", rgb->integer);
	if (exit_code == FAIL || *value == '\0')
		return (ft_return(ERROR, FAIL, "Invalid color", tmp_value));
	exit_code = char_to_rgb(&value, &rgb->g);
	ft_printf("c on return = %d\n", rgb->integer);
	if (exit_code == FAIL || *value == '\0')
		return (ft_return(ERROR, FAIL, "Invalid color", tmp_value));
	exit_code = char_to_rgb(&value, &rgb->b);
	ft_printf("c on return = %d\n", rgb->integer);
	if (exit_code == FAIL)
		return (ft_return(ERROR, FAIL, "Invalid color", tmp_value));
	return (SUCCESS);
}
