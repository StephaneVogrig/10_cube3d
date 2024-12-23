/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_bonus.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 01:36:27 by aska              #+#    #+#             */
/*   Updated: 2024/12/21 04:29:04 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_BONUS_H
# define OPTION_BONUS_H

#include "libft.h"
#include "option_utils_bonus.h"

typedef struct s_option t_option;

int         option_init(t_option *option, int ac, char **av);

#endif