##
## EPITECH PROJECT, 2025
## makefile
## File description:
## Optimized Makefile for macOS + CSFML
##

MAKEFLAGS += --no-print-directory

# ─── Project Info ────────────────────────────────────────────────────────
PROJECT = my_radar
NAME    = my_radar

# ─── Sources ─────────────────────────────────────────────────────────────
SRC = src/main.c \
      src/$(NAME).c \
      src/events/event.c \
      src/main_menu/sprite_main.c \
      src/main_menu/display_main_menu.c \
      src/main_menu/destroy_main_menu.c \
      src/main_menu/text_main.c \
      src/main_menu/main_menu.c \
      src/main_menu/click_main.c \
      src/sounds/effects.c \
      src/sounds/sounds.c \
      src/sounds/destroy_sounds.c \
      src/sounds/music.c \
      src/game/destroy_game.c \
      src/game/display_game.c \
      src/game/text_game.c \
      src/game/game.c \
      src/game/sprite_game.c \
      src/game/plane.c \
      src/game/tower.c \
      src/pause/click_pause.c \
      src/pause/destroy_pause.c \
      src/pause/display_pause.c \
      src/pause/pause.c \
      src/pause/sprite_pause.c \
      src/pause/text_pause.c

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
LIBSFLAGS  = -L ./lib -I ./include -lmy -O3
DEBUGFLAGS = -L ./lib -I ./include -lmy -g3

CFLAGS += -I/opt/homebrew/include -Wno-deprecated-declarations
LDFLAGS = -L./lib -L/opt/homebrew/lib -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

# ─── Tools ───────────────────────────────────────────────────────────────
RM  = rm -rf
ECC = epiclang
CC  = clang
OBJ = $(SRC:.c=.o)

.PHONY: all banner manu_test debug unit_tests tests_run clean fclean coverage help re

# ─── Compilation des .o ──────────────────────────────────────────────────
%.o: %.c
	@$(ECC) $(CFLAGS) -g3 -c $< -o $@

# ─── Macro: Fancy Header ─────────────────────────────────────────────────
define pretty_header
	@echo "$(BOLD)$(RED)+========================================================+$(END)"
	@echo "$(BOLD)$(RED)|$(END)$(BOLD)$(WHITE)$(1)$(END)"
	@echo "$(BOLD)$(RED)+========================================================+$(END)"
endef

# ─── Rules ───────────────────────────────────────────────────────────────
all: $(NAME)

$(NAME): $(OBJ) banner
	@make -C lib/my
	$(call pretty_header, 🚀 creating binary of : $(PROJECT) 🚀)
	@echo "$(BOLD)$(WHITE) done $(END)"
	$(call pretty_header, 🚀 successfully compiled $(PROJECT)! 🚀)
	@make help
	@$(ECC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS) -g3 -lm

banner:
	@echo "$(RED)███╗   ███╗██╗   ██╗     ██████╗  █████╗ ██████╗  █████╗ ██████╗ "
	@echo "████╗ ████║╚██╗ ██╔╝     ██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗"
	@echo "██╔████╔██║ ╚████╔╝      ██████╔╝███████║██║  ██║███████║██████╔╝"
	@echo "██║╚██╔╝██║  ╚██╔╝       ██╔══██╗██╔══██║██║  ██║██╔══██║██╔══██╗"
	@echo "██║ ╚═╝ ██║   ██║███████╗██║  ██║██║  ██║██████╔╝██║  ██║██║  ██║"
	@echo "╚═╝     ╚═╝   ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝"
	@echo "                                                                 "
	@echo "        $(B_RED)$(ITALICS)$(BOLD)$(WHITE)Build with ❤️  by Erwan$(END)"

manu_test:
	$(call pretty_header, 🚀 running : $(PROJECT) 🚀)
	@$(ECC) -o $(NAME) $(SRC) $(LIBSFLAGS)
	@./$(NAME)

debug:
	$(call pretty_header, 🔎 compiling with debug flag for : $(PROJECT) 🔍)
	@$(CC) -o testing $(SRC) $(DEBUGFLAGS)
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
	@open coverage.html

clean:
	$(call pretty_header, 🧹 Cleaning object files 🧹)
	@make clean -C lib/my/
	@$(RM) $(OBJ)

fclean: clean
	$(call pretty_header, 🗑️ Full clean: objects binary tests coverage 🗑️)
	@$(RM) $(NAME) *.gcda *.gcno unit_tests testing *.html *.css *.log
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

# ─── Colors ──────────────────────────────────────────────────────────────
RED = \033[31m
WHITE = \033[37m
B_RED = \033[41m
