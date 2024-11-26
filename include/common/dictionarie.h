/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionarie.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:08:55 by aska              #+#    #+#             */
/*   Updated: 2024/11/26 16:16:26 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARIE_H
# define DICTIONARIE_H

# include "libft.h"

typedef struct s_key_value
{
	char				*key;
	void				*value;
	struct s_key_value	*next;
}						t_dictionaries;

int						dict_insert(t_dictionaries **dict, char *key,
							void *value);
char					*dict_get(t_dictionaries *dict, char *key);
void					dict_destroy(t_dictionaries **dict);

#endif