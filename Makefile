NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Iincludes -Llibft
CFLAGS += -lftprintf -g3 -fsanitize=address

SRC = push_swap.c parse.c movements.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make bonus -C libft
	@echo "libft compiled"
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
	