# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 10:52:20 by ygaiffie          #+#    #+#              #
#    Updated: 2024/09/17 02:04:59 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL				:=	/bin/bash

BLINK_GREEN			:=	\033[5;32m
BGREEN				:=	\033[1;32m
BHYEL				:= 	\033[1;93m
BOLD				:=	\033[1m
NC					:=	\033[0m

CC 					:= 	cc
CFLAGS 				:= 	-Wall -Werror -Wextra -g
LDFLAGS				:=	-L ./lib/libft-plus -lft
MLX					:=	lib/MacroLibx/libmlx.so -lSDL2

SRC_DIR				:=	src/
OBJ_DIR				:=	obj/
LIB_DIR				:=	lib/
DIR_LIST			:=	{init,utils,free_function,dlst_map}
#-- MANDATORY
HEADERS			:=	include/so_long.h
SRCS			:= 	$(SRC_DIR)main.c \
					$(SRC_DIR)data.c \
					$(SRC_DIR)screen.c \
					$(SRC_DIR)draw_line.c \
					$(SRC_DIR)draw_line_to_border.c \
					$(SRC_DIR)draw_line_utils.c \
					$(SRC_DIR)draw_utils.c \
					$(SRC_DIR)vec2i.c \
					$(SRC_DIR)event.c \
					$(SRC_DIR)render.c \
					$(SRC_DIR)mlx.c \
					$(SRC_DIR)player.c \
					$(SRC_DIR)minimap_bonus.c \
					$(SRC_DIR)raycasting.c \
					$(SRC_DIR)debug.c \
					$(SRC_DIR)dda.c \
					$(SRC_DIR)free_function/free_main.c \
					$(SRC_DIR)free_function/free_mlx_utils.c \
					$(SRC_DIR)free_function/free_utils.c \
					$(SRC_DIR)init/cub_init.c \
					$(SRC_DIR)init/map_init.c \
					$(SRC_DIR)init/map_flood_fill.c \
					$(SRC_DIR)init/mlx_init.c \
					$(SRC_DIR)dlst_map/lstmap_op.c \
					$(SRC_DIR)dlst_map/lstmap_del.c \
					$(SRC_DIR)init/organizer.c \
					$(SRC_DIR)utils/check_utils.c \
					$(SRC_DIR)utils/init_utils.c \
					$(SRC_DIR)utils/pretty_utils.c \
					$(SRC_DIR)utils/lstmap_utils.c \
					
OBJS			:= 	$(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

NAME			:= 	cub3d

all: init
	@$(MAKE) -j makeall
	@echo -e "\t$(BLINK_GREEN)$(NAME) = COMPILATION FINISHED !$(NC)"
	@echo -e "$(BOLD)$(NAME)$(NC) is located in $(BOLD)$(shell find . -iname "$(NAME)")$(NC) !\n"

makeall: $(NAME)

libmlx:
	@$(MAKE) -j -C $(LIB_DIR)MacroLibx --no-print-directory

libft:
	@$(MAKE) -j -C $(LIB_DIR)libft-plus --no-print-directory

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $< && echo -e "$(BGREEN)[✔]$(NC)\tCompiling:\t$(BOLD)$(notdir $<)$(NC)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -g -o $@ $(LDFLAGS) $(MLX) -lm && echo -e "$(BGREEN)[✔]$(NC)\tLinking Exe:\t$(BOLD)$@\n"

clean: libclean
	@rm -fr $(OBJ_DIR) && printf "Cleaning : $(OBJ_DIR)\n"

fclean: clean libfclean
	@rm -f $(NAME) && printf "Cleaning: $(NAME) \n"
	@rm -f $(NAME_BONUS)  && printf "Cleaning: $(NAME_BONUS) \n"

re: fclean all

recub:
	@rm -f $(NAME) && printf "Cleaning: $(NAME) \n"
	@$(MAKE) -j all --no-print-directory

libclean:
	@$(MAKE) -C $(LIB_DIR)libft-plus clean --no-print-directory
	# @$(MAKE) -C $(LIB_DIR)MacroLibX clean --no-print-directory

relibft:
	@$(MAKE) -C $(LIB_DIR)libft-plus re --no-print-directory

remacro:
	@$(MAKE) -C $(LIB_DIR)MacroLibX re --no-print-directory

libfclean: libclean
	@$(MAKE) -C $(LIB_DIR)libft-plus fclean --no-print-directory
#	@$(MAKE) -C $(LIB_DIR)MacroLibX fclean --no-print-directory

init: libft libmlx
	@echo -e ""
	@echo -e "\t\t$(BHYEL)┍━━━━━━»•» 🌸 «•«━┑$(NC)"
	@echo -e "\t\t$(BHYEL) CUB3D COMPILATION $(NC)"
	@echo -e "\t\t$(BHYEL)┕━»•» 🌸 «•«━━━━━━┙$(NC)"
	@echo -e ""
#	@$(MAKE) -C $(LIB_DIR)libft-plus --no-print-directory
#	@$(MAKE) -C $(LIB_DIR)MacroLibX --no-print-directory
	@mkdir -p $(OBJ_DIR)$(DIR_LIST) && echo -e "$(BGREEN)[✔]$(NC)\tCreate Directories: $(OBJ_DIR)$(DIR_LIST)$(NC)"

bonus: init $(NAME_BONUS) 
	@echo -e "\t$(BLINK_GREEN)$(NAME_BONUS) = COMPILATION FINISHED !$(NC)"
	@echo -e "$(BOLD)$(NAME_BONUS)$(NC) is located in $(BOLD)$(shell find . -iname "$(NAME_BONUS)")$(NC) !\n"
	@echo -e "\t$(BLINK_GREEN) = COMPILATION FINISHED !$(NC)"
	@echo -e "$(BOLD)$(NC) is located in $(BOLD)$(shell find . -iname "")$(NC) !\n"
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS_BONUS)
	@$(CC) $(CFLAGS) -o $@ -c $< && echo -e "$(BGREEN)[✔]$(NC)\tCompiling:\t$(BOLD)$(notdir $<)$(NC)"

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS)  $(OBJS_BONUS) -o $@ $(LDFLAGS) && echo -e "$(BGREEN)[✔]$(NC)\tLinking Exe:\t$(BOLD)$@\n"

.PHONY: clean fclean all re libclean libfclean bonus relibft remacro
