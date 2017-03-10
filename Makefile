NAME = gnl

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC=get_next_line.c libft/*.c

OBJ=$(SRC:.c=.o)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean
