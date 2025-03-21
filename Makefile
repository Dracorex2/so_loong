NAME = so_long
NAME_BONUS = so_long_bonus

SRCS_BONUS_DIR = bonus/
SRCS_DIR = srcs/
MLX_DIR = mlx/
INCLUDE = includes/

MLX_LIB = libmlx_Linux.a

CC = cc -Wall -Wextra -Werror -g
MLX_FLAGS = -lX11 -lXext

SRCS = so_long.c map_check.c map_check2.c /gnl/get_next_line_utils.c  /gnl/get_next_line.c  move_player.c files_func.c\
/utils/utils.c  /mlx_func/draw.c  /mlx_func/free.c  /mlx_func/init_img.c /mlx_func/init.c

SRCS_BONUS = enemies.c move_enemies.c nbr_windows.c draw_bonus.c

OBJECTS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))
OBJECTS_BONUS = $(addprefix $(SRCS_DIR)$(SRCS_BONUS_DIR), $(SRCS_BONUS:.c=.o))

BONUS_MODE = 0

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ -I includes/ -D BONUS_MODE=$(BONUS_MODE)

all: $(NAME)

$(MLX_DIR)$(MLX_LIB):
	make -C $(MLX_DIR)

$(NAME): $(OBJECTS) $(MLX_DIR)$(MLX_LIB)
		$(CC) $(CFLAGS) $(OBJECTS) $(MLX_DIR)$(MLX_LIB) $(MLX_FLAGS) -o $@ -I$(MLX_DIR) -I$(INCLUDE)

$(NAME_BONUS): $(OBJECTS) $(OBJECTS_BONUS) $(MLX_DIR)$(MLX_LIB)
		$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTS_BONUS) $(MLX_DIR)$(MLX_LIB) $(MLX_FLAGS) -o $@ -I$(MLX_DIR) -I$(INCLUDE)

bonus: BONUS_MODE = 1
bonus: $(NAME_BONUS)

clean:
		rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
		rm -rf $(NAME) $(NAME_BONUS)
		make clean -C $(MLX_DIR)

re: fclean all

.PHONY: mlx
