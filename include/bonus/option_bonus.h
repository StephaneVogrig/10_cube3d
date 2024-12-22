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

typedef struct s_option
{
    int     win_width;
    int     win_height;
    int     fov;
    t_bool  minimap;
}				t_option;

t_option	*option_get_ptr(void);
void    option_init(t_option *option, int ac, char **av);
int	option_get_resolution(t_option *option, char *resolution);


#endif