##
## EPITECH PROJECT, 2026
## ~/epitech/delivery
## File description:
## Makefile
##

CC = epiclang

NAME = test

SRC = main.c

TSRC = my_strlowcase.c \
	   tests/test_my_strlowcase.c

TFLAGS = --coverage -lcriterion -lgcov
GCOVRFLAGS = --gcov-executable "llvm-cov-20 gcov" --exclude tests/

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: all, clean, fclean, re, run
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.gcda *.gcno tests/*.gcda tests/*.gcno

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests

re: fclean all

unit_tests: fclean
	@$(CC) -o unit_tests $(TSRC) $(TFLAGS)

tests_run: unit_tests
	@./unit_tests
	@gcovr $(GCOVRFLAGS)
	@gcovr $(GCOVRFLAGS) --branches
