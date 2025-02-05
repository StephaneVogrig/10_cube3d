/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordonate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:47:44 by aska              #+#    #+#             */
/*   Updated: 2025/02/05 22:18:20 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordonate_bonus.h"

int	extract_coordonate_sprite(t_sprite_lst **sprite_lst, t_lstmap **tmp, int id)
{
	t_lstmap	*sp;

	sp = *tmp;
	next_line_not_empty(tmp);
	if (tmp == NULL)
		return (ft_return(ERROR, FAIL, "unexpected end of file after",
				sp->line));
	if ((*tmp)->line[0] != '[')
		return (ft_return(ERROR, FAIL, "No coordonate for sprite", sp->line));
	while (tmp != NULL && (*tmp)->line[0] == '[')
	{
		if (set_sprite_coordonate((*tmp)->line, sprite_lst, id) != SUCCESS)
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

static int	extract_coordonate(char **pos, t_build_double *build)
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

int	set_sprite_coordonate(char *line, t_sprite_lst **head, int id)
{
	t_build_double	x;
	t_build_double	y;
	char			*pos;

	pos = line;
	ft_bzero(&x, sizeof(x));
	ft_bzero(&y, sizeof(y));
	if (extract_coordonate(&pos, &x) != SUCCESS)
		return (ft_return(ERROR, FAIL, "Invalid coordonate X position", line));
	if (*pos != ';')
		return (ft_return(ERROR, FAIL, "Invalid coordonate separator", line));
	if (extract_coordonate(&pos, &y) != SUCCESS)
		return (ft_return(ERROR, FAIL, "Invalid coordonate Y position", line));
	if (*pos != ']')
		return (ft_return(ERROR, FAIL, "Invalid end coordonate \"]\"", line));
	pos++;
	skip_blank(&pos);
	if (*pos != '\0')
		return (ft_return(ERROR, FAIL, "Stuff after coordonate", line));
	insert_sprite_lst(head, build(&x), build(&y), id);
	return (SUCCESS);
}
