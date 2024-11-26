# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 10:52:20 by ygaiffie          #+#    #+#              #
#    Updated: 2024/11/26 15:33:33 by ygaiffie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL				:=	/bin/bash

BLINK_GREEN			:=	\033[5;32m
BGREEN				:=	\033[1;32m
BHYEL				:= 	\033[1;93m
BOLD				:=	\033[1m
NC					:=	\033[0m

NAME				:= 	cub3d
NAME_BONUS			:=	cub3d_bonus
				
# library ---------------------------------------------------------------------#

LIB_DIR				:=	lib/

LDFLAGS				:=	-L ./lib/libft-plus -lft
MLX					:=	lib/MacroLibx/libmlx.so -lSDL2

# includes --------------------------------------------------------------------#

DIR_INC				:=	include \
						include/bonus \
						include/common \
						include/mandatory \
						lib/libft-plus \
						lib/MacroLibx/includes \
						src

I_FLAG				:=	$(addprefix -I,$(DIR_INC)) -MMD -MP

# sources ---------------------------------------------------------------------#

SRC_DIR				:=	src

# sources common --------------------------------------------------------------#

SRC_COMMON_DIR		:=	common

SRCS_COMMON			:= 	debug.c \
						draw_wall.c \
						fixedpoint.c \
						map.c \
						pixel.c \
						player.c \
						title.c \
						vector.c \
						window.c \
						check_arg.c \
						render/chrono.c \
						lstmap.c \
						stack.c \
						color.c \
						file_load.c \
						img_mlx.c \
						parsing_utils.c \
						gametime.c \
						texture.c \
						parsing/flood_fill_common.c

SRCS_COMMON			:=	$(SRCS_COMMON:%=$(SRC_COMMON_DIR)/%)

# sources madatory only -------------------------------------------------------#

SRC_MAND_DIR		:=	mandatory

SRCS_MANDA			:=	main_manda.c \
						event_manda.c \
						player_move_manda.c \
						floor_ceil_mlx_img.c \
						render/dda_manda.c \
						render/draw_walls_manda.c \
						render/raycasting_manda.c \
						render/render_manda.c \
						parsing/data_manda.c \
						parsing/lstmap_extraction_utils_manda.c \
						parsing/lstmap_extraction_manda.c \
						parsing/flood_fill_manda.c \
						parsing/bitfield_path_valid.c
						
SRCS_MANDA			:=	$(SRCS_MANDA:%=$(SRC_MAND_DIR)/%)

SRCS_MANDA			:=	$(SRCS_COMMON) $(SRCS_MANDA)

SRCS_MANDA			:=	$(SRCS_MANDA:%=$(SRC_DIR)/%)

# sources bonus ---------------------------------------------------------------#

SRC_BONUS_DIR		:=	bonus

SRCS_BONUS 			:=	main_bonus.c \
						event_bonus.c \
						player_move_bonus.c \
						textures_bonus.c \
						render/dda_bonus.c \
						render/draw_walls_bonus.c \
						render/raycasting_bonus.c \
						render/render_bonus.c \
						render/minimap_bonus.c \
						render/minimap_utils_bonus.c \
						render/draw_line_bonus.c \
						render/draw_line_utils_bonus.c \
						render/draw_utils_bonus.c \
						parsing/data_bonus.c \
						parsing/lstmap_extraction_utils_bonus.c \
						parsing/lstmap_extraction_bonus.c \
						parsing/flood_fill_bonus.c \
						parsing/mlx_setup.c \
						id_tex_bonus.c

SRCS_BONUS			:=	$(SRCS_BONUS:%=$(SRC_BONUS_DIR)/%)
# sources ---------------------------------------------------------------------#

SRCS_BONUS			:=	$(SRCS_COMMON) $(SRCS_BONUS)

SRCS_BONUS			:=	$(SRCS_BONUS:%=$(SRC_DIR)/%)

# objects ---------------------------------------------------------------------#

OBJ_DIR				:=	.build/

OBJS_MANDA			:= 	$(SRCS_MANDA:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJS_BONUS			:= 	$(SRCS_BONUS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

DEPS				:=	$(OBJS_MANDA:.o=.d) $(OBJS_BONUS:.o=.d)

# compilation -----------------------------------------------------------------#

CC 					:= 	cc
CFLAGS 				:= 	-Wall -Werror -Wextra -g

#------------------------------------------------------------------------------#
# rules                                                                        #
#------------------------------------------------------------------------------#

all: libft libmlx init
	@$(MAKE) -j makeall
	@echo -e "\t$(BLINK_GREEN)$(NAME) = COMPILATION FINISHED !$(NC)"
	@echo -e "$(BOLD)$(NAME)$(NC) is located in $(BOLD)$(shell find . -iname "$(NAME)")$(NC) !\n"

bonus: libft libmlx init 
	@$(MAKE) -j makebonus
	@echo -e "\t$(BLINK_GREEN)$(NAME_BONUS) = COMPILATION FINISHED !$(NC)"
	@echo -e "$(BOLD)$(NAME_BONUS)$(NC) is located in $(BOLD)$(shell find . -iname "$(NAME_BONUS)")$(NC) !\n"

clean: libclean
	@rm -fr $(OBJ_DIR) && printf "Cleaning : $(OBJ_DIR)\n"

fclean: clean libfclean
	@rm -f $(NAME) && printf "Cleaning: $(NAME) \n"
	@rm -f $(NAME_BONUS)  && printf "Cleaning: $(NAME_BONUS) \n"

libmlx:
	@$(MAKE) -j -C $(LIB_DIR)MacroLibx --no-print-directory

libft:
	@$(MAKE) -j -C $(LIB_DIR)libft-plus --no-print-directory

re: fclean
	@$(MAKE) all

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

init:
	@echo -e ""
	@echo -e "\t\t$(BHYEL)┍━━━━━━»•» 🌸 «•«━┑$(NC)"
	@echo -e "\t\t$(BHYEL) CUB3D COMPILATION $(NC)"
	@echo -e "\t\t$(BHYEL)┕━»•» 🌸 «•«━━━━━━┙$(NC)"
	@echo -e ""

makeall: $(NAME)
makebonus : $(NAME_BONUS)

#------------------------------------------------------------------------------#
# compilation                                                                  #
#------------------------------------------------------------------------------#

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(I_FLAG) -o $@ -c $< && echo -e "$(BGREEN)[✔]$(NC)\tCompiling:\t$(BOLD)$(notdir $<)$(NC)"

-include $(DEPS)

#------------------------------------------------------------------------------#
# linkage                                                                      #
#------------------------------------------------------------------------------#

$(NAME): $(OBJS_MANDA)
	@$(CC) $(CFLAGS) $(OBJS_MANDA) -o $@ $(LDFLAGS) $(MLX) -lm && echo -e "$(BGREEN)[✔]$(NC)\tLinking Exe:\t$(BOLD)$@\n"
	
$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $@ $(LDFLAGS) $(MLX) -lm && echo -e "$(BGREEN)[✔]$(NC)\tLinking Exe:\t$(BOLD)$@\n"

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
