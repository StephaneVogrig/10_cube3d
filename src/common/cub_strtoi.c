/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_strtoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:58:09 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/30 15:40:37 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_strtoi.h"

static inline int	isdigit(const char c)
{
	if ('0' <= c && c <= '9')
		return (TRUE);
	return (FALSE);
}

static inline char	*skip_blank(const char *str)
{
	if (!str)
		return (NULL);
	while (ft_isspace(*str))
		str++;
	return ((char *)str);
}

static inline void	set_endptr(const char *str, char **endptr)
{
	if (endptr)
		*endptr = (char *)str;
}

static inline int	check_overflow(const char **str, int *value, char sign)
{
	if (*value < INT_MAX_DIV_10)
		return (FALSE);
	if (*value > INT_MAX_DIV_10)
	{
		if (sign == '+')
			*value = INT_MAX;
		else
			*value = INT_MIN;
		return (TRUE);
	}
	if (**str <= INT_MAX_LAST_DIGIT)
		return (FALSE);
	if (sign == '+')
	{
		*value = INT_MAX;
		return (TRUE);
	}
	if (**str == INT_MIN_LAST_DIGIT)
		(*str)++;
	*value = INT_MIN;
	return (TRUE);
}

/*
	The cub_strtoi() function converts the initial part of the string in str
    to an integer value.

    The string may begin with an arbitrary amount of white space (as determined
	by isspace(3)) followed by a single optional '+' or '-' sign.

    The remainder of the string is converted to a long value in the obvious
    manner,  stopping  at the first character which is not a valid digit.

    If endptr is not NULL, cub_strtoi() stores the address of the first invalid
    character  in *endptr.  If there were no digits at all, cub_strtoi() stores
    the original value of nptr in *endptr (and returns 0).  In  particular,
    if  *nptr is not '\0' but **endptr is '\0' on return, the entire string
    is valid.

	In case of over/underflow cub_strtoi() function return INT_MAX/MIN
	and *endptr store the adress of the digit which cause the over/underflow.
*/
int	cub_strtoi(const char *str, char **endptr)
{
	int		value;
	char	sign;
	int		overflow;

	set_endptr(str, endptr);
	str = skip_blank(str);
	sign = '+';
	if (*str == '-' || *str == '+')
		sign = *str++;
	if (!isdigit (*str))
		return (0);
	value = 0;
	while (isdigit(*str))
	{
		overflow = check_overflow(&str, &value, sign);
		if (overflow)
			break ;
		value = value * 10 + (*str - '0');
		str++;
	}
	if (sign == '-' && !overflow)
		value *= -1;
	set_endptr(str, endptr);
	return (value);
}
