/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretty_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:12:45 by aska              #+#    #+#             */
/*   Updated: 2024/09/29 01:59:28 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

void    title(void)
{
	title_screen("  CUB3D", YEL);
	ft_printf(RED);
	ft_printf("\t┍━━━━━━━━━━━»•» 🎮 «•«━┑\n");
	ft_printf("\t Dev by Yohann Gaiffier \n");
	ft_printf("\t┕━»•» 🎮 «•«━━━━━━━━");
	ft_printf(HYEL);
	ft_printf("━━━━━━━━━»•» 💣 «•«━┑\n");
	ft_printf("\t\t\t     And Stephane Vogrig \n");
	ft_printf("\t\t\t    ┕━»•» 💣 «•«━━━━━━━━┙\n\n");
	ft_printf(CRESET);
}

