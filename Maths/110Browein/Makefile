NAME	=	110borwein

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -std=c11
LDFLAGS	=	-lm

SRC	=	110borwein.c
OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
