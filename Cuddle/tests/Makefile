##
## EPITECH PROJECT, 2025
## tests/Makefile
## File description:
## Dedicated Makefile for Criterion unit tests
##

MAKEFLAGS += --no-print-directory

# ─── Sources ─────────────────────────────────────────────────────────────
SRCTST =	unit_tests_lib.c \
			\
			../lib/Cuddle/print/my_put_nbr.c \
			../lib/Cuddle/print/my_putchar.c \
			../lib/Cuddle/print/my_putnbr_base.c \
			../lib/Cuddle/print/my_putstr.c \
			../lib/Cuddle/print/my_str_isprintable.c \
			../lib/Cuddle/print/my_show_word_array.c \
			\
			../lib/Cuddle/array/cmp_alpha.c \
			../lib/Cuddle/array/my_array_len.c \
			../lib/Cuddle/array/my_char_array_dup.c \
			../lib/Cuddle/array/sort_word_array.c \
			\
			../lib/Cuddle/math/len_nb.c \
			../lib/Cuddle/math/minimum_int_from_list.c \
			../lib/Cuddle/math/my_compute_power_rec.c \
			../lib/Cuddle/math/my_compute_square_root.c \
			../lib/Cuddle/math/my_find_prime_sup.c \
			../lib/Cuddle/math/my_getnbr.c \
			../lib/Cuddle/math/my_is_prime.c \
			../lib/Cuddle/math/my_isneg.c \
			../lib/Cuddle/math/my_swap.c \
			\
			../lib/Cuddle/string/my_char_isnum.c \
			../lib/Cuddle/string/my_nbr_to_str.c \
			../lib/Cuddle/string/my_revstr.c \
			../lib/Cuddle/string/my_str_isalpha.c \
			../lib/Cuddle/string/my_str_islower.c \
			../lib/Cuddle/string/my_str_isnum.c \
			../lib/Cuddle/string/my_str_isupper.c \
			../lib/Cuddle/string/my_str_to_word_array.c \
			../lib/Cuddle/string/my_strcapitalize.c \
			../lib/Cuddle/string/my_strcmp.c \
			../lib/Cuddle/string/my_strconcat.c \
			../lib/Cuddle/string/my_strcpy.c \
			../lib/Cuddle/string/my_strlen.c \
			../lib/Cuddle/string/my_strlowcase.c \
			../lib/Cuddle/string/my_strncat.c \
			../lib/Cuddle/string/my_strncmp.c \
			../lib/Cuddle/string/my_strncpy.c \
			../lib/Cuddle/string/my_strstr.c \
			../lib/Cuddle/string/my_strupcase.c \
			\
			../lib/Cuddle/memory/free_array.c \
			../lib/Cuddle/memory/my_strdup.c \
			../lib/Cuddle/memory/my_strndup.c \
			\
			../lib/Cuddle/io/get_file_size_nostat.c \
			../lib/Cuddle/io/get_file_size_stat.c \
			../lib/Cuddle/io/openator.c \
			\
			../lib/Cuddle/list/free_list.c \
			../lib/Cuddle/list/get_at.c \
			../lib/Cuddle/list/get_back.c \
			../lib/Cuddle/list/get_front.c \
			../lib/Cuddle/list/insert_node.c \
			../lib/Cuddle/list/list_len.c \
			../lib/Cuddle/list/pop_at.c \
			../lib/Cuddle/list/pop_back.c \
			../lib/Cuddle/list/pop_front.c \
			../lib/Cuddle/list/push_back.c \
			../lib/Cuddle/list/push_front.c \
			../lib/Cuddle/list/search_in_list.c

# ─── Flags ───────────────────────────────────────────────────────────────
CC = clang
RM = rm -rf
TESTSFLAGS = --coverage -lcriterion -lgcov
LIBSFLAGS = -L ../lib -I ../lib/Headers -lcuddle -O3 -Wall -Wextra -Werror -Wshadow
MATHSFLAGS = -lm
GCOVRSTYLE = 'github.dark-green'
LOGS_DIR = ../Logs
COVERAGE_DIR = $(LOGS_DIR)/coverage
COVERAGE_RAW_DIR = $(COVERAGE_DIR)/raw
COVERAGE_HTML = $(COVERAGE_DIR)/index.html
WEBGCOVRFLAGS = --html-theme $(GCOVRSTYLE) --html --html-nested -o $(COVERAGE_HTML)
GCOVRFLAGS = --gcov-executable "llvm-cov-20 gcov" --exclude tests/ --root ..

# ─── Colors ──────────────────────────────────────────────────────────────
END = \033[0m
BOLD = \033[1m
H_GREEN = \033[92m
H_YELLOW = \033[93m

# ─── Rules ───────────────────────────────────────────────────────────────
.PHONY: all unit_tests tests_run coverage clean fclean

all: unit_tests

unit_tests:
	@mkdir -p $(LOGS_DIR) $(COVERAGE_RAW_DIR)
	@$(CC) -o unit_tests $(SRCTST) $(TESTSFLAGS) $(LIBSFLAGS) $(MATHSFLAGS)

tests_run: unit_tests
	@CRITERION_SHOW_STDOUT=1 ./unit_tests > $(LOGS_DIR)/test_output.log 2>&1 || true; \
	if grep -q "FAIL" $(LOGS_DIR)/test_output.log; then \
		echo "$(BOLD)$(H_YELLOW)⚠️  Some tests failed! Check $(LOGS_DIR)/test_output.log for details. ⚠️$(END)"; \
		cat $(LOGS_DIR)/test_output.log; \
		exit 1; \
	fi; \
	echo "$(BOLD)$(H_GREEN)✅ All tests passed! Generating coverage report...$(END)"; \
	gcovr $(GCOVRFLAGS) $(WEBGCOVRFLAGS) > $(LOGS_DIR)/coverage_report.log 2>&1; \
	gcovr $(GCOVRFLAGS) --branches >> $(LOGS_DIR)/coverage_report.log 2>&1; \
	echo "$(BOLD)$(H_GREEN)✅ Tests executed and coverage report generated! Check $(LOGS_DIR)/test_output.log and $(LOGS_DIR)/coverage_report.log for details. 🎉$(END)"

coverage: unit_tests
	@mkdir -p $(LOGS_DIR) $(COVERAGE_RAW_DIR)
	@./unit_tests
	@gcovr $(GCOVRFLAGS) $(WEBGCOVRFLAGS)
	@gcovr $(GCOVRFLAGS) --branches
	@xdg-open $(COVERAGE_HTML)

clean:
	@$(RM) unit_tests *.gcda *.gcno

fclean: clean

