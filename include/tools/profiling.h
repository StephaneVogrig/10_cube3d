/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   profiling.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:28:40 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:18:33 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROFILING_H
# define PROFILING_H

typedef enum e_profile
{
	P_START,
	P_STOP,
	P_PRINT
}		t_profile;

void	profile(int n, t_profile action);

#endif
