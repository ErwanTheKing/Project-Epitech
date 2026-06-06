##
## EPITECH PROJECT, 2026
## ~/epitech/delivery
## File description:
## Makefile
##

CC = epiclang

SRC = src/hashtable.c \
	  src/ht_insert.c \
	  src/ht_delete.c \
	  src/ht_search.c \
	  src/ht_dump.c \
	  src/hash.c \
	  src/res/strlen.c \
	  src/res/strncpy.c \
	  src/res/nbr_to_str.c \
	  src/res/strcmp.c \
	  src/res/str_to_int.c \
	  src/res/dlong_to_str.c \
	  src/res/strdup.c

SRCTST = tests/unit_tests.c

CFLAGS = -Wall -Wextra -Werror -Iinclude
COVFLAGS = --coverage
TFLAGS = -lcriterion -lgcov
GCOVRSTYLE = 'github.dark-green'
WEBGCOVRFLAGS = --html-theme $(GCOVRSTYLE) --html --html-nested -o coverage.html
GCOVRFLAGS = --gcov-executable "llvm-cov-20 gcov" --exclude tests/
HFLAGS = -I include -L . -lhashtable

OBJ = $(SRC:.c=.o)

NAME = libhashtable.a

.PHONY: all, clean, fclean, re, unit_tests, tests_run, coverage, run
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *.gcda *.gcno tests/*.gcda tests/*.gcno
	find . \( -name "*.gcda" -o -name "*.gcno" \) -delete

fclean: clean
	rm -f $(NAME)
	rm -f *.css
	rm -f unit_tests
	rm -f *.html

re: fclean all

run:
	@clang main.c $(HFLAGS)
	@./a.out
	@rm a.out

unit_tests: fclean
	@$(MAKE) CFLAGS="$(CFLAGS) $(COVFLAGS)" all
	@clang-20 -o unit_tests $(SRCTST) $(COVFLAGS) -lcriterion $(HFLAGS) -Wl,--wrap=malloc

tests_run: unit_tests
	@./unit_tests
	@gcovr $(GCOVRFLAGS)
	@gcovr $(GCOVRFLAGS) --branches

coverage: unit_tests
	@./unit_tests
	@gcovr $(GCOVRFLAGS) $(WEBGCOVRFLAGS)
	@gcovr $(GCOVRFLAGS) --branches
	@xdg-open coverage.html
