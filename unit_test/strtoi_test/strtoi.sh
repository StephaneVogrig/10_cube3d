# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    strtoi.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 11:11:43 by svogrig           #+#    #+#              #
#    Updated: 2025/01/30 00:03:30 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC="	../../src/bonus/cub_strtoi_bonus.c
		strtoi_test.c
		unit_test.c
	"

I_FLAG="-I../../include/bonus"

rm strtoi.exe

cc $I_FLAG  $SRC  -Wall -Wextra -Werror -g -o strtoi.exe

./strtoi.exe

rm strtoi.exe
