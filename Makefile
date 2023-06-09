# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 10:35:37 by luntiet-          #+#    #+#              #
#    Updated: 2023/04/26 10:43:24 by oheinzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
CC			= cc
LIBFT		= libft/libft.a
KERNEL		= $(shell uname -a | cut -f 1 -d ' ')
BREW		= $(shell which brew | cut -f 4 -d '/')
MLX42 		= ./MLX42/build/libmlx42.a
MLXFLAGS	= -lglfw -L "$(HOME)/$(BREW)/opt/glfw/lib"
INCLUDE		= -I libft/ -I MLX42/include/MLX42/ -I include/
CFLAGS		= -Wall -Werror -Wextra #-fsanitize=address
LINK_FLAGS	= -L libft -lft #-fsanitize=address

ifeq ($(KERNEL),Linux)
MLXFLAGS	= -Iinclude -ldl -lglfw -pthread -lm
endif

GREEN		= \033[0;32m
CYAN		= \033[0;36m
WHITE		= \033[0m

MATH_DIR	= src/math/
MATH_SRC	=	ray vec_util vec_operations vec_double_operations util \
				vec_clamp double_clamp
MATH		= $(addprefix $(MATH_DIR), $(addsuffix .c, $(MATH_SRC)))

GRAPHICS_DIR	= src/graphics/
GRAPHICS_SRC	= 	window draw hit cast_light cast_shadow hit_sphere \
					hit_cylinder key_input hit_plane hit_cone hit_utils \
					light_movement
GRAPHICS		= $(addprefix $(GRAPHICS_DIR), $(addsuffix .c, $(GRAPHICS_SRC)))

PARSER_DIR		= src/parser/
PARSER_SRC		= handle_input setter getter map parse_obj parse_utils
PARSER			= $(addprefix $(PARSER_DIR), $(addsuffix .c, $(PARSER_SRC)))

OBJECTS_DIR		= src/objects/
OBJECTS_SRC		= camera lighting object vector
OBJECTS			= $(addprefix $(OBJECTS_DIR), $(addsuffix .c, $(OBJECTS_SRC)))

MAIN_DIR		= src/
MAIN_SRC		= main
MAIN			= $(addprefix $(MAIN_DIR), $(addsuffix .c, $(MAIN_SRC)))

SRC_DIR			= src/
OBJ_DIR			= obj/
SRC				= $(MAIN) $(GRAPHICS) $(MATH) $(PARSER) $(OBJECTS)
OBJ				= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

all:		$(NAME)

$(NAME):	$(MLX42) $(LIBFT) $(OBJ_DIR) $(OBJ)
			@$(CC) $(OBJ) $(MLX42) $(MLXFLAGS) $(LINK_FLAGS) -o $(NAME)
			@echo "$(GREEN)miniRT compiled!$(WHITE)"

LSANLIB = /LeakSanitizer/liblsan.a
lsan: CFLAGS += -ILeakSanitizer -Wno-gnu-include-next
lsan: LINK_FLAGS += -LLeakSanitizer -llsan -lc++
lsan: fclean $(LSANLIB)
lsan: all

LSANREP = https://github.com/mhahnFr/LeakSanitizer.git

$(LSANLIB):
	@if [ ! -d "LeakSanitizer" ]; then git clone $(LSANREP); fi
	@$(MAKE) -C LeakSanitizer

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@echo "$(CYAN)Compiling $(WHITE): $<"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
			@mkdir -p $(dir $(OBJ))

$(LIBFT):
			@git submodule init libft
			@git submodule update libft
			@make -C libft

$(MLX42):
			@git submodule init MLX42
			@git submodule update MLX42
			@cd MLX42 && cmake -B build
			@make -C MLX42/build

clean:
			@rm -rf $(OBJ_DIR)
			@echo "$(GREEN)miniRT object files cleaned!$(WHITE)"

fclean:		clean
			@rm -f $(NAME)
			@echo "$(GREEN)miniRTexecutable files cleaned!$(WHITE)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for miniRT!$(WHITE)"

relib:
			@make re -C libft
			@rm -rf MLX42
			@git submodule init MLX42
			@git submodule update MLX42
			@cd MLX42 && cmake -B build
			@make -C MLX42/build

.PHONY:		all clean fclean re
