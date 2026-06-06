##
## EPITECH PROJECT, 2025
## makefile
## File description:
## a make file that is able to do lots of things tests manual tests compiling coverage...
## see "make help"
##

MAKEFLAGS += --no-print-directory

# ─── Project Info ────────────────────────────────────────────────────────
 PROJECT = my_sudo
 NAME	= my_sudo

# ─── Sources ─────────────────────────────────────────────────────────────
SRC = src/main.c \
		src/$(NAME).c \
		src/sudoers.c \
		src/options_u.c

SRCTST = lib/my/my_compute_power_rec.c \
         	   lib/my/my_compute_square_root.c \
               lib/my/my_find_prime_sup.c \
               lib/my/my_getnbr.c \
               lib/my/my_isneg.c \
               lib/my/my_is_prime.c \
               lib/my/my_revstr.c \
               lib/my/my_putchar.c \
               lib/my/my_put_nbr.c \
               lib/my/my_putstr.c \
               lib/my/my_showmem.c \
               lib/my/my_showstr.c \
               lib/my/my_sort_int_array.c \
               lib/my/my_strcapitalize.c \
               lib/my/my_strcat.c \
               lib/my/my_strcmp.c \
               lib/my/my_strcpy.c \
               lib/my/my_strdup.c \
               lib/my/my_str_isalpha.c \
               lib/my/my_str_islower.c \
               lib/my/my_str_isnum.c \
               lib/my/my_str_isprintable.c \
               lib/my/my_str_isupper.c \
               lib/my/my_strlen.c \
               lib/my/my_strlowcase.c \
               lib/my/my_strncat.c \
               lib/my/my_strncmp.c \
               lib/my/my_strncpy.c \
               lib/my/my_strndup.c \
               lib/my/my_strstr.c \
               lib/my/my_str_to_word_array.c \
               lib/my/my_strupcase.c \
               lib/my/my_swap.c \
               lib/my/my_show_word_array.c \
               lib/my/my_putnbr_base.c \
               lib/my/my_char_isnum.c \
               lib/my/my_char_is_specifier.c \
               lib/my/len_nb.c \
               lib/my/specifier_biga.c \
               lib/my/specifier_a.c \
               lib/my/specifier_b.c \
               lib/my/specifier_bigb.c \
               lib/my/specifier_c.c \
               lib/my/specifier_di.c \
               lib/my/specifier_bige.c \
               lib/my/specifier_e.c \
               lib/my/specifier_fbigf.c \
               lib/my/specifier_bigg.c \
               lib/my/specifier_g.c \
               lib/my/specifier_m.c \
               lib/my/specifier_n.c \
               lib/my/specifier_o.c \
               lib/my/specifier_p.c \
               lib/my/specifier_po.c \
               lib/my/specifier_bigs.c \
               lib/my/specifier_s.c \
               lib/my/specifier_u.c \
               lib/my/specifier_bigx.c \
               lib/my/specifier_x.c \
         	   lib/my/struct_prefill.c \
         	   lib/my/is_specifier.c \
         	   lib/my/fill_format_struct.c \
         	   lib/my/fill_specifier_struct.c \
         	   lib/my/fill_lenght_struct.c \
         	   lib/my/fill_width_struct.c \
         	   lib/my/fill_flag_struct.c \
         	   lib/my/erase_flags.c \
         	   lib/my/manage_spaces.c \
         	   lib/my/manage_zeros.c \
         	   lib/my/fill_precision_struct.c \
         	   lib/my/my_printf.c \
         	   lib/my/verif_function.c \
		 	   tests/unit_tests_lib.c

# ─── Flags ───────────────────────────────────────────────────────────────
TESTSFLAGS = --coverage -lcriterion -lgcov
LIBSFLAGS = -L ./lib -I ./include -lmy -O3
DEBUGFLAGS = -L ./lib -I ./include -lmy -g3
ERRORFLAGS =

# ─── Tools ───────────────────────────────────────────────────────────────
RM = rm -rf
ECC = epiclang
CC = clang
LIBS = -L ./lib -I ./include -lmy -g3
OBJ = $(SRC:.c=.o)

.PHONY: all banner manu_test debug unit_tests tests_run clean fclean coverage help re

%.o: %.c
	@$(ECC) $(ERRORFLAGS) -g3 -L../lib -lmy -Wno-unused-command-line-argument -c $< -o $@

# ─── Macro: Fancy Header ─────────────────────────────────────────────────
define pretty_header
	@echo "$(BOLD)$(RED)+========================================================+$(END)"
	@echo "$(BOLD)$(RED)|$(END)$(BOLD)$(WHITE)$(1)$(END)"
	@echo "$(BOLD)$(RED)+========================================================+$(END)"
endef

# ─── Rules ───────────────────────────────────────────────────────────────
all:	$(NAME)

$(NAME): $(OBJ) banner
	@make -C lib/my
	$(call pretty_header, 🚀 creating binary of : $(PROJECT) 🚀)
	@echo "$(BOLD)$(WHITE) done $(END)"
	$(call pretty_header, 🚀 succesfuly compiled $(PROJECT)! 🚀)
	@make help
	@$(ECC) -o $(NAME) $(OBJ) $(LIBSFLAGS) $(ERRORFLAGS) -lcrypt -g3

banner:
	@echo "$(RED)███╗   ███╗██╗   ██╗     ███████╗██╗   ██╗██████╗  ██████╗ ";
	@echo "████╗ ████║╚██╗ ██╔╝     ██╔════╝██║   ██║██╔══██╗██╔═══██╗";
	@echo "██╔████╔██║ ╚████╔╝      ███████╗██║   ██║██║  ██║██║   ██║";
	@echo "██║╚██╔╝██║  ╚██╔╝       ╚════██║██║   ██║██║  ██║██║   ██║";
	@echo "██║ ╚═╝ ██║   ██║███████╗███████║╚██████╔╝██████╔╝╚██████╔╝";
	@echo "╚═╝     ╚═╝   ╚═╝╚══════╝╚══════╝ ╚═════╝ ╚═════╝  ╚═════╝ ";
	@echo "                                                           ";
	@echo "        $(B_RED)$(ITALICS)$(BOLD)$(WHITE)Build with ❤️  by Erwan$(END)"

manu_test:
	$(call pretty_header, 🚀 running : $(PROJECT) 🚀)
	@$(ECC) -o $(NAME) $(SRCMANU) $(LIBSFLAGS)
	@./$(NAME)

debug:
	$(call pretty_header, 🔎 compiling with debug flag for : $(PROJECT) 🔍)
	@$(CC) -o testing $(SRCMANU) $(DEBUGFLAGS)
	@echo "$(BOLD)$(WHITE) done $(END)"
	$(call pretty_header, 🐐 calling valgrind 🐐)
	@valgrind --leak-check=full --log-file=valgrind.log ./$(NAME)

unit_tests:
	@$(CC) -o unit_tests $(SRCTST) $(TESTSFLAGS) $(LIBSFLAGS)

tests_run: unit_tests
	@./unit_tests
	@gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/
	@gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/ --branches

coverage: unit_tests
	@./unit_tests
	@gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/ --html-theme 'github.dark-green' --html --html-nested -o coverage.html
	@gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/ --branches
	@xdg-open coverage.html

clean:
	$(call pretty_header, 🧹 Cleaning object files 🧹)
	@make clean -C lib/my/
	@$(RM) $(OBJ)

fclean: clean
	$(call pretty_header, 🗑️ Full clean: objects binary tests coverage 🗑️)
	@$(RM) $(NAME) *.gcda *.gcno unit_tests testing testing *.html *.css *.log
	@make fclean -C lib/my/

re: fclean all

# ─── Help ────────────────────────────────────────────────────────────────
help:
	$(call pretty_header,📘 Available Commands 📘)
	@echo "$(RED)  make all        $(END)→ Compile the project"
	@echo "$(RED)  make debug      $(END)→ Compile with debug and run Valgrind"
	@echo "$(RED)  make manu_test  $(END)→ Run manual test binary"
	@echo "$(RED)  make tests_run  $(END)→ Run unit tests and coverage"
	@echo "$(RED)  make coverage   $(END)→ run unit tests and coverage but display the coverage on a html window"
	@echo "$(RED)  make clean      $(END)→ Clean object files"
	@echo "$(RED)  make fclean     $(END)→ Clean all (bin/tests/coverage)"
	@echo "$(RED)  make re         $(END)→ Recompile everything"


# ─── Styles ──────────────────────────────────────────────────────────────
END = \033[0m
BOLD = \033[1m
ITALICS = \033[3m
UNDER = \033[4m
REV = \033[7m

# ─── Colors ──────────────────────────────────────────────────────────────
GREY = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PURPLE = \033[35m
CYAN = \033[36m
WHITE = \033[37m
H_GREY = \033[90m
H_RED = \033[91m
H_GREEN = \033[92m
H_YELLOW = \033[93m
H_BLUE = \033[94m
H_PURPLE = \033[95m
H_CYAN = \033[96m
H_WHITE = \033[97m

# ─── Background ──────────────────────────────────────────────────────────
B_GREY = \033[40m
B_RED = \033[41m
B_GREEN = \033[42m
B_YELLOW = \033[43m
B_BLUE = \033[44m
B_PURPLE = \033[45m
B_CYAN = \033[46m
B_WHITE = \033[47m
HB_GREY = \033[100m
HB_RED = \033[101m
HB_GREEN = \033[102m
HB_YELLOW = \033[103m
HB_BLUE = \033[104m
HB_PURPLE = \033[105m
HB_CYAN = \033[106m
HB_WHITE = \033[107m