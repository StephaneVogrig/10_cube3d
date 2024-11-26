/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionarie.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:08:55 by aska              #+#    #+#             */
/*   Updated: 2024/11/26 02:43:28 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARIE_H
# define DICTIONARIE_H

# include "libft.h"

typedef struct s_key_value
{
	char			*key;
	void			*value;
	t_dictionaries	*next;
}					t_dictionaries;

int					dict_insert(t_dictionaries **dict, char *key, void *value);
char				*dict_get(t_dictionaries *dict, char *key);
void				dict_destroy(t_dictionaries **dict);

#endif