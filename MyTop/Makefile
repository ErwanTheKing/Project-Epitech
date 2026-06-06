##
## EPITECH PROJECT, 2025
## makefile
## File description:
## a make file that is able to do lots of things tests manual tests compiling coverage...
## see "make help"
##

MAKEFLAGS += --no-print-directory

# ─── Project Info ────────────────────────────────────────────────────────
 PROJECT = My_Top
 NAME	= my_top
 LIB_NAME = libmy.a

# ─── Sources ─────────────────────────────────────────────────────────────
SRCMANU =   src/main.c \
			src/init.c \
			src/header/header.c \
			src/header/header_meta_data.c \
			src/header/header_task_count.c \
			src/header/header_cpu_info.c \
			src/header/header_cpu_print.c \
			src/header/header_mem_info.c \
			src/header/header_swap_info.c \
			src/core/title.c \
			src/core/body.c \
			src/core/count_runnings.c \
			src/core/column/print_username.c \
			src/core/column/print_pr.c \
			src/core/column/print_ni.c \
			src/core/column/print_virt.c \
			src/core/column/print_res.c \
			src/core/column/print_shr.c \
			src/core/column/print_state.c \
			src/flags/get_flags.c \
			src/core/column/print_cpu_percentage.c \
			src/core/column/print_mem.c \

SRCTST = 		tests/unit_tests_lib.c \
         		lib/my/printing/my_put_nbr.c \
         		lib/my/printing/my_putchar.c \
         		lib/my/printing/my_putnbr_base.c \
         		lib/my/printing/my_putstr.c \
         		lib/my/printing/my_str_isprintable.c \
         		lib/my/printing/my_show_word_array.c \
         		lib/my/opperations/cmp_alpha.c \
         		lib/my/opperations/my_compute_power_rec.c \
         		lib/my/opperations/my_compute_square_root.c \
         		lib/my/opperations/my_strcmp.c \
         		lib/my/opperations/my_strncmp.c \
         		lib/my/opperations/minimum_int_from_list.c \
         		lib/my/opperations/sort_word_array.c \
         		lib/my/opperations/my_swap.c \
         		lib/my/opperations/my_isneg.c \
         		lib/my/opperations/my_is_prime.c \
         		lib/my/opperations/my_array_len.c \
         		lib/my/opperations/my_char_isnum.c \
         		lib/my/opperations/my_find_prime_sup.c \
         		lib/my/opperations/my_getnbr.c \
         		lib/my/opperations/len_nb.c \
         		lib/my/manage_str/my_nbr_to_str.c \
         		lib/my/manage_str/my_revstr.c \
         		lib/my/manage_str/my_str_isalpha.c \
         		lib/my/manage_str/my_str_islower.c \
         		lib/my/manage_str/my_str_isnum.c \
         		lib/my/manage_str/my_str_isupper.c \
         		lib/my/manage_str/my_str_to_word_array.c \
         		lib/my/manage_str/my_strcapitalize.c \
         		lib/my/manage_str/my_strconcat.c \
         		lib/my/manage_str/my_strcpy.c \
         		lib/my/manage_str/my_strlen.c \
         		lib/my/manage_str/my_strlowcase.c \
         		lib/my/manage_str/my_strncat.c \
         		lib/my/manage_str/my_strncpy.c \
         		lib/my/manage_str/my_strstr.c \
         		lib/my/manage_str/my_strupcase.c \
         		lib/my/malloc/free_array.c \
         		lib/my/malloc/get_file_size_nostat.c \
         		lib/my/malloc/get_file_size_stat.c \
         		lib/my/malloc/my_strndup.c \
         		lib/my/malloc/my_strdup.c \
         		lib/my/malloc/openator.c \
         		lib/my/malloc/my_char_array_dup.c \
         		lib/my/linked_lists/free_list.c \
         		lib/my/linked_lists/get_at.c \
         		lib/my/linked_lists/get_back.c \
         		lib/my/linked_lists/get_front.c \
         		lib/my/linked_lists/insert_node.c \
         		lib/my/linked_lists/list_len.c \
         		lib/my/linked_lists/pop_at.c \
         		lib/my/linked_lists/pop_back.c \
         		lib/my/linked_lists/pop_front.c \
         		lib/my/linked_lists/push_back.c \
         		lib/my/linked_lists/push_front.c \
         		lib/my/linked_lists/search_in_list.c

# ─── Flags ───────────────────────────────────────────────────────────────
TESTSFLAGS = --coverage -lcriterion -lgcov
LIBSFLAGS = -L ./lib -I ./include -lmy -O3 -Wall -Wextra
DEBUGFLAGS = -L ./lib -I ./include -lmy -g3 -Wall -Wextra
GCOVRSTYLE = 'github.dark-green'
WEBGCOVRFLAGS = --html-theme $(GCOVRSTYLE) --html --html-nested -o coverage.html
GCOVRFLAGS = --gcov-executable "llvm-cov-20 gcov" --exclude tests/
NCURSESFLAGS = -lncurses
MATHSFLAGS = -lm
LIBS = -L ./lib -I ./include -lmy

# ─── Tools ───────────────────────────────────────────────────────────────
RM = rm -rf
ECC = epiclang
CC = clang
ARGUMENTS =

# ─── random ───────────────────────────────────────────────────────────────
TO_RM = *.gcda *.gcno unit_tests testing testing *.html *.css *.log main


%.o: %.c
	@$(ECC) -L../lib -lmy -Wno-unused-command-line-argument -c $< -o $@

# ─── Macro: Fancy Header ─────────────────────────────────────────────────
define pretty_header
	@echo "$(BOLD)$(H_PURPLE)╔═══════════════════════════════════════════════════════════════╗$(END)"
	@echo "$(BOLD)$(H_PURPLE)║$(END)$(BOLD)$(WHITE)$(1)$(END)"
	@echo "$(BOLD)$(H_PURPLE)╚═══════════════════════════════════════════════════════════════╝$(END)"
endef

# ─── Rules ───────────────────────────────────────────────────────────────
.PHONY: all manu_test run debug unit_tests tests_run coverage clean fclean re banner
all:	$(NAME)

$(NAME): banner
	@echo ""
	@echo "$(BOLD)$(H_PURPLE)╔═══════════════════════════════════════════════════════════════╗$(END)"
	@echo "$(BOLD)$(H_PURPLE)║  $(H_CYAN)🚀 Starting Compilation Process$(H_PURPLE) 🚀                             $(END)"
	@echo "$(BOLD)$(H_PURPLE)╚═══════════════════════════════════════════════════════════════╝$(END)"
	@echo ""
	@make -C lib/my
	$(call pretty_header, 🚀 creating binary of : $(PROJECT) 🚀)
	@echo "$(BOLD)$(WHITE) done $(END)"
	$(call pretty_header, 🚀 succesfuly compiled $(PROJECT)! 🚀)
	@$(ECC) -o $(NAME) $(SRCMANU) $(LIBSFLAGS) $(NCURSESFLAGS) $(MATHSFLAGS)

banner:
	@echo "$(PURPLE)                                                                                                                                                                                                                                               ";
	@echo "██████╗ ██╗   ██╗██╗██╗  ████████╗    ██╗    ██╗██╗████████╗██╗  ██╗    ██╗  ██╗███████╗ █████╗ ██████╗ ████████╗";
	@echo "██╔══██╗██║   ██║██║██║  ╚══██╔══╝    ██║    ██║██║╚══██╔══╝██║  ██║    ██║  ██║██╔════╝██╔══██╗██╔══██╗╚══██╔══╝";
	@echo "██████╔╝██║   ██║██║██║     ██║       ██║ █╗ ██║██║   ██║   ███████║    ███████║█████╗  ███████║██████╔╝   ██║   ";
	@echo "██╔══██╗██║   ██║██║██║     ██║       ██║███╗██║██║   ██║   ██╔══██║    ██╔══██║██╔══╝  ██╔══██║██╔══██╗   ██║   ";
	@echo "██████╔╝╚██████╔╝██║███████╗██║       ╚███╔███╔╝██║   ██║   ██║  ██║    ██║  ██║███████╗██║  ██║██║  ██║   ██║   ";
	@echo "╚═════╝  ╚═════╝ ╚═╝╚══════╝╚═╝        ╚══╝╚══╝ ╚═╝   ╚═╝   ╚═╝  ╚═╝    ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ";
	@echo "                                                                                                                                                                                                                                               ";
	@echo "                                                 ██████╗ ██╗   ██╗";
	@echo "                                                 ██╔══██╗╚██╗ ██╔╝";
	@echo "                                                 ██████╔╝ ╚████╔╝ ";
	@echo "                                                 ██╔══██╗  ╚██╔╝  ";
	@echo "                                                 ██████╔╝   ██║   ";
	@echo "                                                 ╚═════╝    ╚═╝   ";
	@echo "                 ";
	@echo "       ███████╗ █████╗  ██████╗██╗  ██╗ █████╗        ██╗       ███████╗██████╗ ██╗    ██╗ █████╗ ███╗   ██╗";
	@echo "       ██╔════╝██╔══██╗██╔════╝██║  ██║██╔══██╗       ██║       ██╔════╝██╔══██╗██║    ██║██╔══██╗████╗  ██║";
	@echo "       ███████╗███████║██║     ███████║███████║    ████████╗    █████╗  ██████╔╝██║ █╗ ██║███████║██╔██╗ ██║";
	@echo "       ╚════██║██╔══██║██║     ██╔══██║██╔══██║    ██╔═██╔═╝    ██╔══╝  ██╔══██╗██║███╗██║██╔══██║██║╚██╗██║";
	@echo "       ███████║██║  ██║╚██████╗██║  ██║██║  ██║    ██████║      ███████╗██║  ██║╚███╔███╔╝██║  ██║██║ ╚████║";
	@echo "       ╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝    ╚═════╝      ╚══════╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═══╝";
	@echo " $(END)                                                                                                    ";

manu_test:
	$(call pretty_header, 🚀 compiling : $(PROJECT) 🚀)
	@$(ECC) -o $(NAME) $(SRCMANU) $(LIBSFLAGS)

run:
	$(call pretty_header, 🚀 running : $(PROJECT) 🚀)
	@./$(NAME) $(ARGUMENTS)

debug:
	$(call pretty_header, 🔎 compiling with debug flag for : $(PROJECT) 🔍)
	@$(CC) -o $(NAME) $(SRCMANU) $(DEBUGFLAGS) $(NCURSESFLAGS)
	@echo "$(BOLD)$(WHITE) done $(END)"
	@echo ""
	@echo "$(BOLD)$(H_GREEN)✅ Debug build ready! Time to hunt bugs! 🎯$(END)"
	@echo ""
	@echo "$(H_PURPLE)🔍 Running Valgrind memory check...$(END)"
	@valgrind --leak-check=full \
    	--show-leak-kinds=all \
    	--track-origins=yes \
    	--log-file=valgrind.log \
		./$(NAME) 2>&1 || true
	@echo "$(H_CYAN)📝 Valgrind report saved to $(H_YELLOW)valgrind.log$(END)"
	@echo ""
	@if grep -q "ERROR SUMMARY: 0 errors" valgrind.log; then \
    	echo "$(BOLD)$(H_GREEN)✨ No memory errors detected! Perfect! ✨$(END)"; \
  	else \
    	echo "$(BOLD)$(H_YELLOW)⚠️  Memory issues detected! Check valgrind.log for details$(END)"; \
    fi
	@echo ""

unit_tests: re
	@$(CC) -o unit_tests $(SRCTST) $(TESTSFLAGS) $(LIBSFLAGS)

tests_run: unit_tests
	@./unit_tests
	@gcovr $(GCOVRFLAGS) $(WEBGCOVRFLAGS)
	@gcovr $(GCOVRFLAGS) --branches

coverage: unit_tests
	@./unit_tests
	@gcovr $(GCOVRFLAGS) $(WEBGCOVRFLAGS)
	@gcovr $(GCOVRFLAGS) --branches
	@xdg-open coverage.html

clean:
	$(call pretty_header, 🧹 Cleaning object files 🧹)
	@make clean -C lib/my/

fclean: clean
	$(call pretty_header, 🗑️ Full clean: objects binary tests coverage 🗑️)
	@$(RM) $(NAME) $(TO_RM) $(name)
	@make fclean -C lib/my/

re: fclean all

#──── optional ─────────────────────────────────────────────────────────────────
.PHONY: help
help:
	@echo ""
	@echo "$(BOLD)$(CYAN)╔══════════════════════════════════════════════════════════════════════════╗$(END)"
	@echo "$(BOLD)$(CYAN)║                          $(H_WHITE)MAKEFILE HELP MENU$(CYAN)                              ║$(END)"
	@echo "$(BOLD)$(CYAN)╠══════════════════════════════════════════════════════════════════════════╣$(END)"
	@echo "$(BOLD)$(CYAN)║$(END) $(BOLD)$(H_GREEN)Project:$(END) $(YELLOW)$(PROJECT)$(END)                                                           $(BOLD)$(CYAN)║$(END)"
	@echo "$(BOLD)$(CYAN)║$(END) $(BOLD)$(H_GREEN)Library:$(END) $(YELLOW)$(LIB_NAME)$(END)                                                         $(BOLD)$(CYAN)║$(END)"
	@echo "$(BOLD)$(CYAN)╚══════════════════════════════════════════════════════════════════════════╝$(END)"
	@echo ""
	@echo "$(BOLD)$(H_PURPLE)┌─ Basic Build Targets ────────────────────────────────────────────────────┐$(END)"
	@echo "  $(H_GREEN)make$(END) / $(H_GREEN)make all$(END)       Build the library and executable (default)"
	@echo "  $(H_GREEN)make $(LIB_NAME)$(END)      Build only the static library"
	@echo "  $(H_GREEN)make $(NAME)$(END)  Build only the final executable"
	@echo "$(BOLD)$(H_PURPLE)└──────────────────────────────────────────────────────────────────────────┘$(END)"
	@echo ""
	@echo "$(BOLD)$(H_PURPLE)┌─ Development & Debug ────────────────────────────────────────────────────┐$(END)"
	@echo "  $(H_GREEN)make debug$(END)             Compile with debug + run Valgrind memory check"
	@echo "$(BOLD)$(H_PURPLE)└──────────────────────────────────────────────────────────────────────────┘$(END)"
	@echo ""
	@echo "$(BOLD)$(H_PURPLE)┌─ Testing & Coverage ─────────────────────────────────────────────────────┐$(END)"
	@echo "  $(H_GREEN)make unit_tests$(END)        Compile unit tests with Criterion"
	@echo "  $(H_GREEN)make tests_run$(END)         Run unit tests and generate coverage report"
	@echo "  $(H_GREEN)make coverage$(END)          Run tests, generate coverage & open in browser"
	@echo "$(BOLD)$(H_PURPLE)└──────────────────────────────────────────────────────────────────────────┘$(END)"
	@echo ""
	@echo "$(BOLD)$(H_PURPLE)┌─ Cleaning ───────────────────────────────────────────────────────────────┐$(END)"
	@echo "  $(H_GREEN)make clean$(END)             Remove object files and temporary files"
	@echo "  $(H_GREEN)make fclean$(END)            Remove all generated files (clean + binaries)"
	@echo "  $(H_GREEN)make re$(END)                Rebuild everything from scratch (fclean + all)"
	@echo "$(BOLD)$(H_PURPLE)└──────────────────────────────────────────────────────────────────────────┘$(END)"
	@echo ""
	@echo "$(BOLD)$(H_PURPLE)┌─ Information ────────────────────────────────────────────────────────────┐$(END)"
	@echo "  $(H_GREEN)make help$(END)              Display this help message"
	@echo "$(BOLD)$(H_PURPLE)└──────────────────────────────────────────────────────────────────────────┘$(END)"
	@echo ""
	@echo "$(BOLD)$(H_CYAN)📁 Directories:$(END)"
	@echo "  • Library:     $(YELLOW)$(LIB_DIR)/$(END)"
	@echo "  • Includes:    $(YELLOW)$(INC_DIR)/$(END)"
	@echo "  • Objects:     $(YELLOW)$(OBJ_DIR)/$(END)"
	@echo "  • Tests:       $(YELLOW)$(TEST_DIR)/$(END)"
	@echo ""
	@echo "$(BOLD)$(H_CYAN)🔧 Compiler:$(END) $(YELLOW)$(ECC)$(END)"
	@echo "$(BOLD)$(H_CYAN)🚩 Flags:$(END)    $(YELLOW)$(LIBSFLAGS)$(END)"
	@echo ""
	@echo "$(GREEN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@echo ""


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
