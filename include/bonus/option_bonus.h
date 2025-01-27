/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:08:44 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 16:08:53 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_BONUS_H
# define OPTION_BONUS_H

# include "libft.h"
# include "option_utils_bonus.h"
# include "window.h"

typedef struct s_option	t_option;

int						option_init(t_option *option, int ac, char **av);

#endif