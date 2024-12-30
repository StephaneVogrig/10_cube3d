/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:28:21 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/30 21:16:03 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

char	choose_char(t_bool test, char val_if_true, char val_if_false);
float	choose_float(t_bool test, float val_if_true, float val_if_false);

#endif