/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:28:21 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:04:44 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

char	choose_char(t_bool test, char val_if_true, char val_if_false);
float	choose_float(t_bool test, float val_if_true, float val_if_false);

#endif