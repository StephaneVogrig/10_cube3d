/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:07:13 by aska              #+#    #+#             */
/*   Updated: 2025/01/31 13:24:19 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_VALUE_H
# define KEY_VALUE_H

# include "libft.h"

typedef struct s_key_value
{
	char	*key;
	char	*value;
}			t_key_value;

t_status	set_key_value(t_key_value *kv, char *line);

#endif