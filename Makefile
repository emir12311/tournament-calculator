NAME = tournament_calculator
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) after_norm_formatting.c -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f scores.txt

re: fclean all
