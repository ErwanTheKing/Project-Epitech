##
## EPITECH PROJECT, 2025
## makefile
## File description:
## a make file that is able to do lots of things tests manual tests compiling coverage...
## see "make help"
##

MAKEFLAGS += --no-print-directory

# ─── Project Info ────────────────────────────────────────────────────────
 PROJECT = my_hunter
 NAME	= my_hunter

# ─── Sources ─────────────────────────────────────────────────────────────
SRC = main.c \
	  main/main_menu.c \
	  main/button_main.c \
	  main/execute_main.c  \
	  main/text_main.c \
	  settings/settings_menu.c \
	  settings/button_settings.c \
	  settings/button_settings2.c \
	  settings/text_settings.c \
	  settings/execute_settings.c \
	  settings/execute_settings2.c \
	  pause/pause_menu.c \
	  pause/button_pause.c \
	  pause/execute_pause.c \
	  game/manage_sprite.c \
	  game/$(NAME).c \
	  game/execute_hunter.c \
	  game/text_game.c \
	  game/sprite_hunter.c \
	  game/destroy_sprite.c \
	  game/draw_sprite.c \
	  game/ammo_sprite.c \
	  loose/loose_menu.c \
	  loose/sprite_loose.c \
	  chose_mode/chose_mode.c \
	  chose_mode/sprite_chose_mode.c

SRCTST = tests/unit_tests_lib.c

# ─── Flags ───────────────────────────────────────────────────────────────
TESTSFLAGS = --coverage -lcriterion -lgcov
CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
CFLAGS = -Werror -Wextra -Wall -g3 -O3

# ─── Tools ───────────────────────────────────────────────────────────────
RM = rm -rf
ECC = epiclang
CC = clang
OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(ECC) $(CFLAGS) -g3 -L../lib -lmy -Wno-unused-command-line-argument -c $< -o $@

.PHONY: all banner run debug clean fclean help re mac

# ─── Macro: Fancy Header ─────────────────────────────────────────────────
define pretty_header
	@echo "$(BOLD)$(RED)+========================================================+$(END)"
	@echo "$(BOLD)$(RED)|$(END)$(BOLD)$(WHITE)$(1)$(END)"
	@echo "$(BOLD)$(RED)+========================================================+$(END)"
endef

# ─── Rules ───────────────────────────────────────────────────────────────
all:	$(NAME)

$(NAME): $(OBJ) banner
	$(call pretty_header, 🚀 creating binary of : $(PROJECT) 🚀)
	@echo "$(BOLD)$(WHITE) done $(END)"
	$(call pretty_header, 🚀 succesfuly compiled $(PROJECT)! 🚀)
	@make help
	@$(ECC) -o $(NAME) $(OBJ) $(CSFML) $(CFLAGS)

banner:
	@echo "$(RED)██╗  ██╗██╗   ██╗███╗   ██╗████████╗███████╗██████╗ ";
	@echo "██║  ██║██║   ██║████╗  ██║╚══██╔══╝██╔════╝██╔══██╗";
	@echo "███████║██║   ██║██╔██╗ ██║   ██║   █████╗  ██████╔╝";
	@echo "██╔══██║██║   ██║██║╚██╗██║   ██║   ██╔══╝  ██╔══██╗";
	@echo "██║  ██║╚██████╔╝██║ ╚████║   ██║   ███████╗██║  ██║";
	@echo "╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝   ╚══════╝╚═╝  ╚═╝";
	@echo "                                                    ";
	@echo "        $(B_RED)$(ITALICS)$(BOLD)$(WHITE)Build with ❤️  by Erwan$(END)"

mac:
	@make -C mac/

run: all
	@./$(NAME)

debug:
	$(call pretty_header, 🔎 compiling with debug flag for : $(PROJECT) 🔍)
	@$(CC) -o $(NAME) $(SRC) $(CSFML)
	@echo "$(BOLD)$(WHITE) done $(END)"
	$(call pretty_header, 🐐 calling valgrind 🐐)
	@valgrind --leak-check=full --log-file=valgrind.log ./$(NAME)

unit_tests:
	@$(CC) -o unit_tests $(SRCTST) $(TESTSFLAGS)

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
	@$(RM) $(OBJ)

fclean: clean
	$(call pretty_header, 🗑️ Full clean: objects binary tests coverage 🗑️)
	@$(RM) $(NAME) *.gcda *.gcno unit_tests testing testing *.html *.css *.log

re: fclean all

# ─── Help ────────────────────────────────────────────────────────────────
help:
	$(call pretty_header,📘 Available Commands 📘)
	@echo "$(RED)  make all        $(END)→ Compile the project"
	@echo "$(RED)  make debug      $(END)→ Compile with debug and run Valgrind"
	@echo "$(RED)  make run        $(END)→ Run manual test binary"
	@echo "$(RED)  make mac        $(END)→ Compile the project for MacBook"
	@echo "$(RED)  make clean      $(END)→ Clean object files"
	@echo "$(RED)  make fclean     $(END)→ Clean all (bin/tests/coverage)"
	@echo "$(RED)  make re         $(END)→ Recompile everything"
	@echo "$(RED)$(BOLD)  ./my_hunter -h  $(END)→ Help menu"

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