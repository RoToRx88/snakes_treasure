SRC	= main.c \
	  move.c

NAME	= snake

OBJ	= $(SRC:.c=.o)

#FLAG	= -Wextra -Werror -Wall -pthread -pedantic -ansi -O3
FLAG	= -O3 -pthread -lSDL

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(OBJ) $(NAME)

re: fclean all

s: re
	make clean
	clear
	@echo -e "[Makefile]-----------------Starting program-------------------"
	@./$(NAME)
