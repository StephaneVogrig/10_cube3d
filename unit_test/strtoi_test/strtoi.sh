# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    strtoi.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 11:11:43 by svogrig           #+#    #+#              #
#    Updated: 2025/01/30 15:35:52 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC="	../../src/common/cub_strtoi.c
		strtoi_test.c
		unit_test.c
	"

I_FLAG="-I../../include/common
		-I../../lib/libft-plus
		"

rm strtoi.exe

cc $I_FLAG  $SRC "../../lib/libft-plus/libft.a" -Wall -Wextra -Werror -g -o strtoi.exe

./strtoi.exe

rm strtoi.exe
