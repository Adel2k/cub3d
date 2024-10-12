NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address # -Imlx -Iinclude 
# LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

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

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re