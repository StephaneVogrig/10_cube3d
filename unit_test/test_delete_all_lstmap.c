/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_delete_all_lstmap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:11:59 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/03 16:50:41 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common/lstmap.h"

int	main(void)
{
	t_lstmap *lst;

	lst = NULL;
	lst = insert_end_lstmap(&lst, NULL);
	delete_all_lstmap(&lst);
	return (0);
}