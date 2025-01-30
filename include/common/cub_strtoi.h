/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_strtoi.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:02:18 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/30 15:28:19 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRTOI_BONUS_H
# define CUB_STRTOI_BONUS_H

# include <limits.h>
# include <stddef.h>
# include "libft.h"


# ifndef FALSE
#  define FALSE 0
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# define INT_MAX_LAST_DIGIT '7'
# define INT_MAX_DIV_10 214748364

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# define INT_MIN_LAST_DIGIT '8'

int	cub_strtoi(const char *nptr, char **endptr);

#endif
