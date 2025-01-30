/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:53:38 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/30 12:34:17 by aska             ###   ########.fr       */
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

static int	char_to_rgb(char *value, char **endptr, unsigned char *rgb)
{
	int c;
	
	c = cub_strtoi(value, endptr);
	if (c < 0 || c > 255)
		return (FAIL);
	*rgb = (unsigned char)c;
	skip_blank(endptr);
	if (**endptr == ',')
		(*endptr)++;
	else if (**endptr == '\0')
		return (SUCCESS);
	else
		return (FAIL);
	return (SUCCESS);
}

int	color_set_rgb(t_rgb *rgb, char *value)
{
	int		exit_code;
	char	*tmp_value;
	char	*endptr;

	tmp_value = value;
	endptr = NULL;
	exit_code = char_to_rgb(value, &endptr, &rgb->r);
	if (exit_code == FAIL || *endptr == '\0')
		return (ft_return(ERROR, FAIL, "Invalid color", value));
	tmp_value = endptr;
	exit_code = char_to_rgb(tmp_value, &endptr, &rgb->g);
	if (exit_code == FAIL || *endptr == '\0')
		return (ft_return(ERROR, FAIL, "Invalid color", value));
	tmp_value = endptr;
	exit_code = char_to_rgb(tmp_value, &endptr, &rgb->b);
	if (exit_code == FAIL)
		return (ft_return(ERROR, FAIL, "Invalid color", value));
	rgb->a = 255;
	return (SUCCESS);
}
