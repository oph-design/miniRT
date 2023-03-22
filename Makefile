
NAME		= miniRT
CC			= cc
LIBFT		= libft/libft.a
MLX42 		= ./MLX42/build/libmlx42.a
MLXFLAGS	= -lglfw -L "$(HOME)/.brew/opt/glfw/lib"
RL_VERSION	= readline-8.1.2
INCLUDE		= -I include/
CFLAGS		= -g -Wall -Werror -Wextra

GREEN		= \033[0;32m
CYAN		= \033[0;36m
WHITE		= \033[0m

SRC_DIR			= src/
SRC_FILES		= main
SRC				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ_DIR			= obj/
OBJ				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all:		$(NAME)

$(NAME):	$(MLX42) $(LIBFT) $(OBJ_DIR) $(OBJ)
			@$(CC) $(LIBFT) $(MLX42) $(LINK_FLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)
			@echo "$(GREEN)miniRT compiled!$(WHITE)"

LSANLIB = /LeakSanitizer/liblsan.a
lsan: CFLAGS += -ILeakSanitizer -Wno-gnu-include-next
lsan: LINK_FLAGS += -LLeakSanitizer -llsan -lc++
lsan: fclean $(LSANLIB)
lsan: all

$(LSANLIB):
	@if [ ! -d "LeakSanitizer" ]; then git clone https://github.com/mhahnFr/LeakSanitizer.git; fi
	@$(MAKE) -C LeakSanitizer

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@echo "$(CYAN)Compiling $(WHITE): $<"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
			@mkdir -p obj

$(LIBFT):
			@git submodule init libft
			@git submodule update libft
			@make -C libft

$(MLX42):
			@git submodule init MLX42
			@git submodule update MLX42
			@cd MLX42 && cmake -B build
			@cd MLX42 && cmake --build build -j4

clean:
			@rm -rf $(OBJ_DIR)
			@echo "$(GREEN)miniRT object files cleaned!$(WHITE)"

fclean:		clean
			@rm -f $(NAME)
			@echo "$(GREEN)miniRTexecutable files cleaned!$(WHITE)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for miniRT!$(WHITE)"

.PHONY:		all clean fclean re
