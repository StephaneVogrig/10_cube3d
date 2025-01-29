/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_strtoi.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:02:18 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/29 22:27:51 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRTOI_H
# define CUB_STRTOI_H

# include <limits.h>
# include <stddef.h>
// # include "vs_type.h"

# define INT_MAX_LAST_DIGIT '7'
# define INT_MIN_LAST_DIGIT '8'

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef TRUE
#  define TRUE 1
# endif

int	cub_strtoi(const char *nptr, char **endptr);

#endif
