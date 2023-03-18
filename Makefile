# --- Source ---

SRC = so_long.c
#LIBFT = cd libft && make
#LIB = libft/libft.a

# --- Constants ---

NAME = so_long
HEADER = include/so_long.h
CC = gcc
CFLAGS = -Wextra -Wall -Werror -g -fsanitize=address

# --- Objects ---

OBJ = $(SRC:.c=.o)

# --- Compile ---

all: $(NAME)

$(NAME): dir_obj
	@$(CC) $(CFLAGS) -c source/$(SRC) -o obj/$(OBJ)
	@$(CC) $(CFLAGS) obj/$(OBJ) $(HEADER) -o $(NAME)

dir_obj:
	@mkdir -p obj

clean:
	@rm -rf obj/$(OBJ) obj

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all so_long clean fclean re