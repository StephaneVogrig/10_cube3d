/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:40:12 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/30 00:19:51 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void    print_state(t_state state)
{
	if (state == INFO)
	{
		ft_putstr_fd(BCYN "INFO" CRESET, 1);
		ft_putstr_fd(" : ", 1);
	}
	else if (state == WARNING)
	{
		ft_putstr_fd(BYEL "WARNING" CRESET, 1);
		ft_putstr_fd(" : ", 1);
	}
	else if (state == ERROR || state == PERROR)
	{
		ft_putstr_fd(BRED "ERROR" CRESET, 2);
		ft_putstr_fd(" : ", 2);
	}
}

static void	print_msg(t_state state, char *add_msg, char *add_msg_supp)
{
	if (state == PERROR)
		perror(add_msg);
	else if (state != ERROR)
	{
		ft_putstr_fd(add_msg, 1);
		ft_putstr_fd(": ", 1);
		ft_putstr_fd(add_msg_supp, 1);
		ft_putstr_fd("\n", 1);
	}
	else
	{
		ft_putstr_fd(add_msg, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(add_msg_supp, 2);
		ft_putstr_fd("\n", 2);
	}
}

int	ft_return(t_state state, int return_code, char *add_msg, char *add_msg_supp)
{
	if (DEBUG_MODE >= 2)
		print_state(state);
	else if (DEBUG_MODE == 1 && state == ERROR)
		ft_putstr_fd("Error\n", 2);
	if (add_msg != NULL && DEBUG_MODE > 0)
	{
		if (state == PERROR)
			perror(add_msg);
		else
			print_msg(state, add_msg, add_msg_supp);
	}
	return(return_code);
}
