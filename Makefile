# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 10:52:20 by ygaiffie          #+#    #+#              #
#    Updated: 2024/09/29 03:34:30 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL				:=	/bin/bash

BLINK_GREEN			:=	\033[5;32m
BGREEN				:=	\033[1;32m
BHYEL				:= 	\033[1;93m
BOLD				:=	\033[1m
NC					:=	\033[0m

NAME			:= 	cub3d
				
# library ---------------------------------------------------------------------#

LIB_DIR				:=	lib/

LDFLAGS				:=	-L ./lib/libft-plus -lft
MLX					:=	lib/MacroLibx/libmlx.so -lSDL2


# includes --------------------------------------------------------------------#

DIR_INC			:=	include \
					lib/libft-plus \
					lib/MacroLibx/includes

I_FLAG			:=	$(addprefix -I,$(DIR_INC)) -MMD -MP

# sources ---------------------------------------------------------------------#

SRC_DIR				:=	src/

SRCS			:= 	main.c \
					check_utils.c \
					cub_init.c \
					data.c \
					debug.c \
					draw_line.c \
					draw_line_to_border.c \
					draw_line_utils.c \
					draw_utils.c \
					event.c \
					free_main.c \
					free_mlx_utils.c \
					free_utils.c \
					init_utils.c \
					lstmap_del.c \
					lstmap_op.c \
					lstmap_utils.c \
					map.c \
					pixel.c \
					pretty_utils.c \
					render.c \
					vec2i.c \
					window.c \
					player.c \
					minimap_bonus.c \
					raycasting.c \
					dda.c \
					chrono.c \
					texture.c \
					screen.c
#					map_flood_fill.c

SRCS			:=	$(SRCS:%=$(SRC_DIR)%)

# objects ---------------------------------------------------------------------#

OBJ_DIR				:=	obj/

OBJS			:= 	$(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# dependencies ----------------------------------------------------------------#

DEPS			:=	$(OBJS:.o=.d)


# compilation -----------------------------------------------------------------#

CC 					:= 	cc
CFLAGS 				:= 	-Wall -Werror -Wextra -g

#------------------------------------------------------------------------------#
# rules                                                                        #
#------------------------------------------------------------------------------#

all: init
	@$(MAKE) -j makeall
	@echo -e "\t$(BLINK_GREEN)$(NAME) = COMPILATION FINISHED !$(NC)"
	@echo -e "$(BOLD)$(NAME)$(NC) is located in $(BOLD)$(shell find . -iname "$(NAME)")$(NC) !\n"

makeall: $(NAME)

libmlx:
	@$(MAKE) -j -C $(LIB_DIR)MacroLibx --no-print-directory

libft:
	@$(MAKE) -j -C $(LIB_DIR)libft-plus --no-print-directory


clean: #libclean
	@rm -fr $(OBJ_DIR) && printf "Cleaning : $(OBJ_DIR)\n"

fclean: clean #libfclean
	@rm -f $(NAME) && printf "Cleaning: $(NAME) \n"
	@rm -f $(NAME_BONUS)  && printf "Cleaning: $(NAME_BONUS) \n"

re: fclean all

recub:
	@rm -f $(NAME) && printf "Cleaning: $(NAME) \n"
	@$(MAKE) -j -C all --no-print-directory

libclean:
	@$(MAKE) -C $(LIB_DIR)libft-plus clean --no-print-directory
	@$(MAKE) -C $(LIB_DIR)MacroLibx clean --no-print-directory

relibft:
	@$(MAKE) -C $(LIB_DIR)libft-plus re --no-print-directory

remacro:
	@$(MAKE) -C $(LIB_DIR)MacroLibx re --no-print-directory

libfclean: libclean
	@$(MAKE) -C $(LIB_DIR)libft-plus fclean --no-print-directory
	@$(MAKE) -C $(LIB_DIR)MacroLibx fclean --no-print-directory

init: libft libmlx
	@echo -e ""
	@echo -e "\t\t$(BHYEL)┍━━━━━━»•» 🌸 «•«━┑$(NC)"
	@echo -e "\t\t$(BHYEL) CUB3D COMPILATION $(NC)"
	@echo -e "\t\t$(BHYEL)┕━»•» 🌸 «•«━━━━━━┙$(NC)"
	@echo -e ""
	@mkdir -p $(OBJ_DIR)$(DIR_LIST) && echo -e "$(BGREEN)[✔]$(NC)\tCreate Directories: $(OBJ_DIR)$(DIR_LIST)$(NC)"

bonus: init $(NAME_BONUS) 
	@echo -e "\t$(BLINK_GREEN)$(NAME_BONUS) = COMPILATION FINISHED !$(NC)"
	@echo -e "$(BOLD)$(NAME_BONUS)$(NC) is located in $(BOLD)$(shell find . -iname "$(NAME_BONUS)")$(NC) !\n"
	@echo -e "\t$(BLINK_GREEN) = COMPILATION FINISHED !$(NC)"
	@echo -e "$(BOLD)$(NC) is located in $(BOLD)$(shell find . -iname "")$(NC) !\n"

#------------------------------------------------------------------------------#
# compilation                                                                  #
#------------------------------------------------------------------------------#

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(I_FLAG) -o $@ -c $< && echo -e "$(BGREEN)[✔]$(NC)\tCompiling:\t$(BOLD)$(notdir $<)$(NC)"

-include $(DEPS)

#------------------------------------------------------------------------------#
# linkage                                                                      #
#------------------------------------------------------------------------------#

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS) $(MLX) -lm && echo -e "$(BGREEN)[✔]$(NC)\tLinking Exe:\t$(BOLD)$@\n"
	
$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS)  $(OBJS_BONUS) -o $@ $(LDFLAGS) && echo -e "$(BGREEN)[✔]$(NC)\tLinking Exe:\t$(BOLD)$@\n"

#------------------------------------------------------------------------------#
# specifications                                                               #
#------------------------------------------------------------------------------#

.PHONY: clean \
		fclean \
		all \
		re \
		libclean \
		libfclean \
		bonus \
		relibft \
		remacro
