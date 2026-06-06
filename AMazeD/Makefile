##
## EPITECH PROJECT, 2025
## my_printf
## File description:
## Makefile
##

SRC = 	src/main.c							\
		src/amazed.c						\
		src/parsing/general_parsing.c		\
		src/parsing/robot.c					\
		src/parsing/room.c					\
		src/parsing/link.c					\
		src/free/free_all.c					\
		src/parthing_lab/algo.c				\
		src/robot_move/robot_choice.c		\
		src/parthing_lab/end_and_start.c	\

TEST_SRC = 		src/amazed.c						\
		   		src/parsing/general_parsing.c		\
		   		src/parsing/robot.c					\
		   		src/parsing/room.c					\
		   		src/parsing/link.c					\
		   		src/free/free_all.c					\
		   		src/parthing_lab/algo.c				\
		   		src/robot_move/robot_choice.c		\
		   		src/parthing_lab/end_and_start.c	\
		   		tests/unit_tests.c					\

OBJ = 	$(SRC:.c=.o)

TEST_NAME = unit_tests

NAME =	amazed

all:	$(NAME)

$(NAME): do_lib $(OBJ)
	epiclang -o $(NAME) $(SRC) -lmy -Llib

unit_tests: all
	@epiclang -o $(TEST_NAME) $(TEST_SRC) -Llib -lmy --coverage -lcriterion -lgcov

tests_run: unit_tests
	@./$(TEST_NAME)
	@gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/

do_lib:
	make -C lib/my/

clean:
	@rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my/
	@rm -f $(NAME)
	@rm -f $(TEST_NAME)

re:	fclean all
