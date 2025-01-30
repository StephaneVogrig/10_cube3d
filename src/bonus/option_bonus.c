/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 01:30:59 by aska              #+#    #+#             */
/*   Updated: 2025/01/30 12:46:21 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option_bonus.h"

static void	option_init_default(t_option *option)
{
	option->win_width = WIN_W;
	option->win_height = WIN_H;
	option->fov = 1;
	option->minimap = FALSE;
}

static int	option_parser(char *key, char *value, t_option *option)
{
	if (ft_strcmp(key, "--resolution") == 0)
		return (option_get_resolution(option, value));
	else if (ft_strcmp(key, "--minimap") == 0)
		option->minimap = TRUE;
	else
		return (FAIL);
	return (SUCCESS);
}

int	option_init(t_option *option, int ac, char **av)
{
	int			i;
	int			exit_code;
	t_key_value	argument;

	if (ac < 2)
		ft_display(ERROR, "No map file");
	if (ac < 2)
		return (print_help());
	i = 2;
	exit_code = 0;
	option_init_default(option);
	while (i < ac)
	{
		exit_code = option_tokenizer(&argument.key, &argument.value, av[i++]);
		if (exit_code == FAIL)
			return (print_help());
		exit_code = option_parser(argument.key, argument.value, option);
		if (exit_code == FAIL)
			return (print_help());
	}
	return (exit_code);
}
