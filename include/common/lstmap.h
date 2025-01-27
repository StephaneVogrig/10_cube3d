/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:10:08 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 16:04:38 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTMAP_H
# define LSTMAP_H

# include "libft.h"

typedef struct s_lstmap
{
	char			*line;
	struct s_lstmap	*next;
	struct s_lstmap	*prev;
}					t_lstmap;

t_lstmap			*insert_end_lstmap(t_lstmap **head, char *line);
void				delete_node_lstmap(t_lstmap **head, t_lstmap *del_node);
void				delete_all_lstmap(t_lstmap **head);

#endif