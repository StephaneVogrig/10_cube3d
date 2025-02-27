# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 10:52:20 by ygaiffie          #+#    #+#              #
#    Updated: 2025/02/06 15:46:22 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
MAKEFLAGS += --no-print-directory --silent
endif

SHELL				:=	/bin/bash

BLINK_GREEN			:=	\033[5;32m
BGREEN				:=	\033[1;32m
BHYEL				:= 	\033[1;93m
BOLD				:=	\033[1m
NC					:=	\033[0m

NAME				:= 	cub3D
NAME_BONUS			:=	cub3D_bonus
				
# library ---------------------------------------------------------------------#

LDFLAGS				:=	-Llibft -lft
MLX					:=	MacroLibx/libmlx.so -lSDL2

# includes --------------------------------------------------------------------#

DIR_INC				:=	include \
						include/bonus \
						include/common \
						include/mandatory \
						include/tools \
						libft \
						MacroLibx/includes \
						src

I_FLAG				:=	$(addprefix -I,$(DIR_INC)) -MMD -MP

# sources ---------------------------------------------------------------------#

SRC_DIR				:=	src

# sources common --------------------------------------------------------------#

SRC_COMMON_DIR		:=	common

SRCS_COMMON			:= 	axis.c \
						check_arg.c \
						color.c \
						cub_strtoi.c \
						dda_utils.c \
						file_load.c \
						file_utils.c \
						gametime.c \
						gridbox.c \
						img_mlx.c \
						key.c \
						key_value.c \
						lstmap.c \
						lstmap_utils.c \
						map.c \
						parsing_utils.c \
						player.c \
						position.c \
						ray.c \
						stack.c \
						texture.c \
						title.c \
						utils.c \
						vector.c \
						window.c \
						parsing/flood_fill_common.c \
						render/draw_wall_utils.c \
						render/strip_util.c \
						render/wall_screen_height.c

SRCS_COMMON			:=	$(SRCS_COMMON:%=$(SRC_COMMON_DIR)/%)

# sources madatory only -------------------------------------------------------#

SRC_MAND_DIR		:=	mandatory

SRCS_MANDA			:=	main_manda.c \
						data_manda.c \
						dda_manda.c \
						event_manda.c \
						player_move_manda.c \
						textures_manda.c \
						floor_ceil_mlx_img_manda.c \
						game_loop_manda.c \
						parsing/lstmap_extraction_manda.c \
						parsing/flood_fill_manda.c \
						parsing/bitfield_path_valid.c \
						parsing/tex_path_manda.c \
						render/draw_wall_manda.c \
						render/draw_walls_manda.c \
						render/raycasting_manda.c \
						render/render_manda.c \
						render/strip_manda.c
						
SRCS_MANDA			:=	$(SRCS_MANDA:%=$(SRC_MAND_DIR)/%)

SRCS_MANDA			:=	$(SRCS_COMMON) $(SRCS_MANDA)

SRCS_MANDA			:=	$(SRCS_MANDA:%=$(SRC_DIR)/%)

# sources bonus ---------------------------------------------------------------#

SRC_BONUS_DIR		:=	bonus

SRCS_BONUS 			:=	main_bonus.c \
						asset_bonus.c \
						asset_utils_bonus.c \
						cell_bonus.c \
						data_bonus.c \
						dda_bonus.c \
						event_bonus.c \
						fog_bonus.c \
						game_loop_bonus.c \
						mouse_utils_bonus.c \
						player_move_bonus.c \
						pointer_table_bonus.c \
						door/door_bonus.c \
						door/door_collide_bonus.c \
						door/door_hit_bonus.c \
						door/door_inside_bonus.c \
						door/door_open_bonus.c \
						door/door_open_list_bonus.c \
						door/door_utils_bonus.c \
						interface/draw_utils_bonus.c \
						interface/draw_img_interface_bonus.c \
						interface/draw_img_minimap_bonus.c \
						interface/interface_bonus.c \
						interface/interface_utils_bonus.c \
						interface/interface_render_bonus.c \
						interface/interface_event_bonus.c \
						interface/tile_rules_bonus.c \
						parsing/check_asset_bonus.c \
						parsing/coordonate_bonus.c \
						parsing/map_bonus.c \
						parsing/lstmap_extraction_bonus.c \
						parsing/lstmap_to_asset_bonus.c \
						parsing/mlx_setup_bonus.c \
						parsing/lstmap_bonus.c \
						parsing/asset_lst_bonus.c \
						parsing/asset_lst_utils_bonus.c \
						parsing/sprite_lst_bonus.c \
						render/draw_floor_ceil_bonus.c \
						render/draw_walls_bonus.c \
						render/draw_wall_bonus.c \
						render/raycasting_bonus.c \
						render/render_bonus.c \
						render/strip_bonus.c \
						sprite/sprite_bonus.c \
						sprite/sprite_collect_bonus.c \
						sprite/sprite_draw_bonus.c \
						sprite/sprite_render_bonus.c

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
CFLAGS 				:= 	-Wall -Werror -Wextra

#------------------------------------------------------------------------------#
# rules                                                                        #
#------------------------------------------------------------------------------#

all: init
	@$(MAKE) -j makeall
	@echo -e "\t$(BLINK_GREEN)$(NAME) = COMPILATION FINISHED !$(NC)"
	@echo -e "$(BOLD)$(NAME)$(NC) is located in $(BOLD)$(shell find . -iname "$(NAME)")$(NC) !\n"

bonus: init 
	@$(MAKE) -j makebonus
	@echo -e "\t$(BLINK_GREEN)$(NAME_BONUS) = COMPILATION FINISHED !$(NC)"

clean: libclean
	@rm -fr $(OBJ_DIR) && printf "Cleaning : $(OBJ_DIR)\n"

fclean: clean libfclean
	@rm -f $(NAME) && printf "Cleaning: $(NAME) \n"
	@rm -f $(NAME_BONUS)  && printf "Cleaning: $(NAME_BONUS) \n"

re: fclean
	@$(MAKE) all

recub:
	@rm -fr $(OBJ_DIR) && printf "Cleaning : $(OBJ_DIR)\n"
	@rm -f $(NAME) && printf "Cleaning: $(NAME) \n"
	@$(MAKE) -j makeall --no-print-directory

libclean:
	@$(MAKE) -C libft clean --no-print-directory
	@$(MAKE) -C MacroLibx clean --no-print-directory

relibft:
	@$(MAKE) -j -C libft re --no-print-directory

remacro:
	@$(MAKE) -j -C MacroLibx re --no-print-directory

libfclean:
	@$(MAKE) -C libft fclean --no-print-directory
	@$(MAKE) -C MacroLibx fclean --no-print-directory

init:
	@echo -e ""
	@echo -e "\t\t$(BHYEL)┍━━━━━━»•» 🌸 «•«━┑$(NC)"
	@echo -e "\t\t$(BHYEL) CUB3D COMPILATION $(NC)"
	@echo -e "\t\t$(BHYEL)┕━»•» 🌸 «•«━━━━━━┙$(NC)"
	@echo -e ""

test: all
	./$(NAME) 42.cub

testbonus: bonus
	./$(NAME)_bonus maps_bonus/test/42bonus.cub

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
	@$(MAKE) -j -C libft --no-print-directory
	@$(MAKE) -j -C MacroLibx --no-print-directory
	@$(CC) $(CFLAGS) $(OBJS_MANDA) -o $@ $(LDFLAGS) $(MLX) -lm && echo -e "$(BGREEN)[✔]$(NC)\tLinking Exe:\t$(BOLD)$@\n"
	
$(NAME_BONUS): $(OBJS_BONUS)
	@$(MAKE) -j -C libft --no-print-directory
	@$(MAKE) -j -C MacroLibx --no-print-directory
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
		remacro	\
		recub \
		test \
		testbonus \
		init \
		makeall \
		makebonus
