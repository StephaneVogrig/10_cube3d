/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:22:33 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/09/11 16:45:50 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char   **ft_tab_f(char **tab)
{
    int i;

    if (tab == NULL)
        return(NULL);
    i = 0;
    while (tab[i] != NULL)
    {
        ft_free(tab[i]);
        i++;
    }
    ft_free(tab);
    return (NULL);
}
