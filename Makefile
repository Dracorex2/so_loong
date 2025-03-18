NAME = so_long

SRCS_DIR = srcs/
MLX_DIR = mlx/
INCLUDE = includes/

MLX_LIB = libmlx_Linux.a

CC = gcc -Wall -Wextra -Werror -g
CFLAGS =
MLX_FLAGS = -lX11 -lXext

SRCS = main.c map_check.c map_check2.c /gnl/get_next_line_utils.c  /gnl/get_next_line.c  move_player.c files_func.c\
/utils/utils.c  /mlx_func/draw.c  /mlx_func/free.c  /mlx_func/init_img.c   /mlx_func/init.c enemies.c

OBJECTS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

BONUS_MODE = 0

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ -D BONUS_MODE=$(BONUS_MODE)

all: mlx $(NAME)

mlx:
	make -sC $(MLX_DIR)

$(NAME): $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) $(MLX_DIR)$(MLX_LIB) $(MLX_FLAGS) -o $@ -I$(MLX_DIR) -I$(INCLUDE)

bonus: BONUS_MODE = 1
bonus: clean mlx $(NAME)

clean:
		rm -rf $(OBJECTS)

fclean: clean
		rm -rf $(NAME)
		make clean -sC $(MLX_DIR)

re: fclean all

.PHONY: mlx
