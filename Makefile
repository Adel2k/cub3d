NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx -Iinclude #-g3 -fsanitize=address
# LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

HEADERS =	include/cub3d.h \
			include/get_next_line.h

SRCS_DIR = source/

OBJS_DIR = objs/

SRCS_NAME = main.c \
			validation.c \
			utils.c \
			get_next_line.c \
			get_next_line_utils.c \
			split.c \
			draw_utils.c \
			init.c \
			list_utils.c \
			checkings.c \
			errors_free.c \
			utils2.c \
			algorithm.c \
			animation.c \
			drawing.c \
			game.c \
			exiting.c \
			move_keys.c \
			raycasting.c \
			starting_game.c \
			texture_valid.c \
			view.c \
			minimap.c \


OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(MLXFLAGS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re