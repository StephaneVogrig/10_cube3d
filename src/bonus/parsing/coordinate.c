/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:47:44 by aska              #+#    #+#             */
/*   Updated: 2025/02/04 21:35:31 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinate.h"

int	extract_coordinate_sprite(t_sprite_lst **sprite_lst, t_lstmap **tmp, int id)
{
	t_lstmap	*sp;

	sp = *tmp;
	next_line_not_empty(tmp);
	if (tmp == NULL)
		return (ft_return(ERROR, FAIL, "unexpected end of file after",
				sp->line));
	if ((*tmp)->line[0] != '[')
		return (ft_return(ERROR, FAIL, "No coordinate for sprite", sp->line));
	while (tmp != NULL && (*tmp)->line[0] == '[')
	{
		if (set_sprite_coordinate((*tmp)->line, sprite_lst, id) != SUCCESS)
			return (FAIL);
		next_line_not_empty(tmp);
	}
	return (SUCCESS);
}

static double	build(t_build_double *build)
{
	int		power;
	int		decimal;

	power = 0;
	decimal = build->decimal;
	while (decimal != 0)
	{
		decimal /= 10;
		power++;
	}
	build->result = build->integer + (build->decimal / pow(10, power));
	return (build->result);
}

static int	extract_coordinate(char **pos, t_build_double *build)
{
	char	*endptr;

	endptr = NULL;
	(*pos)++;
	build->integer = cub_strtoi(*pos, &endptr);
	if (*pos == endptr || ft_isdigit(*endptr) == TRUE)
		return (FAIL);
	*pos = endptr;
	if (ft_isthis(**pos, ".,"))
	{
		(*pos)++;
		build->decimal = cub_strtoi(*pos, &endptr);
		if (*pos == endptr || ft_isdigit(*endptr) == TRUE || build->decimal < 0)
			return (FAIL);
		*pos = endptr;
	}
	skip_blank(pos);
	return (SUCCESS);
}

int	set_sprite_coordinate(char *line, t_sprite_lst **head, int id)
{
	t_build_double	x;
	t_build_double	y;
	char			*pos;

	pos = line;
	ft_bzero(&x, sizeof(x));
	ft_bzero(&y, sizeof(y));
	if (extract_coordinate(&pos, &x) != SUCCESS)
		return (ft_return(ERROR, FAIL, "Invalid coordinate X position", line));
	if (*pos != ';')
		return (ft_return(ERROR, FAIL, "Invalid coordinate separator", line));
	if (extract_coordinate(&pos, &y) != SUCCESS)
		return (ft_return(ERROR, FAIL, "Invalid coordinate Y position", line));
	if (*pos != ']')
		return (ft_return(ERROR, FAIL, "Invalid end coordinate \"]\"", line));
	pos++;
	skip_blank(&pos);
	if (*pos != '\0')
		return (ft_return(ERROR, FAIL, "Stuff after coordinate", line));
	insert_sprite_lst(head, build(&x), build(&y), id);
	return (SUCCESS);
}
