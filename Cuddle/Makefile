##
## EPITECH PROJECT, 2025
## makefile
## File description:
## a make file that is able to do lots of things tests manual tests compiling coverage...
## see "make help"
##

MAKEFLAGS += --no-print-directory

# ─── Project Info ────────────────────────────────────────────────────────
 PROJECT = Cuddle
 NAME	= cuddle
 LIB_NAME = libcuddle.a

# ─── Sources ─────────────────────────────────────────────────────────────
SRCMANU =	Src/main.c \

# ─── Test sources are defined in tests/Makefile ──────────────────────────

# ─── Flags ───────────────────────────────────────────────────────────────
TESTSFLAGS = --coverage -lcriterion -lgcov
LIBSFLAGS = -L ./lib -I ./include -lcuddle -O3 -Wall -Wextra -Werror -Wshadow -Wno-unused-parameter
DEBUGFLAGS = -L ./lib -I ./include -g3 -lcuddle -lm
GCOVRSTYLE = 'github.dark-green'
LOGS_DIR = Logs
COVERAGE_DIR = $(LOGS_DIR)/coverage
COVERAGE_RAW_DIR = $(COVERAGE_DIR)/raw
COVERAGE_HTML = $(COVERAGE_DIR)/index.html
WEBGCOVRFLAGS = --html-theme $(GCOVRSTYLE) --html --html-nested -o $(COVERAGE_HTML)
GCOVRFLAGS = --gcov-executable "llvm-cov-20 gcov" --exclude tests/
NCURSESFLAGS = -lncurses
MATHSFLAGS = -lm
LIBS = -L ./lib -I ./include -lcuddle
CSFMLFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system

# ─── Tools ───────────────────────────────────────────────────────────────
RM = rm -rf
ECC = epiclang
CC = clang
ARGUMENTS =

# ─── random ───────────────────────────────────────────────────────────────
TO_RM = *.gcda *.gcno unit_tests testing testing *.html *.css *.log main Logs libcuddle.a
OBJMANU = $(SRCMANU:.c=.o)


%.o: %.c
	@printf "$(H_CYAN)Compiling$(END) $(BOLD)$<$(END) ... \n"
	@$(ECC) -L./lib -I./include -Wno-unused-command-line-argument -c $< -o $@ 2>&1 > /dev/null && \
		echo "$(BOLD)$(H_GREEN)[ OK ]$(END)" || \
		(echo "$(BOLD)$(H_RED)[ FAIL ]$(END)" && $(ECC) -L./lib -I./include -Wno-unused-command-line-argument -c $< -o $@ && exit 1)

# ─── Macro: Fancy Header ─────────────────────────────────────────────────
define pretty_header
	@echo "$(BOLD)$(H_PURPLE)╔═══════════════════════════════════════════════════════════════╗$(END)"
	@echo "$(BOLD)$(H_PURPLE)║$(END)$(BOLD)$(WHITE)$(1)$(END)"
	@echo "$(BOLD)$(H_PURPLE)╚═══════════════════════════════════════════════════════════════╝$(END)"
endef

# ─── Rules ───────────────────────────────────────────────────────────────
.PHONY: all manu_test run debug unit_tests tests_run coverage functional_tests clean fclean re banner lib_build lib_build_debug
all:	$(NAME)

$(NAME): banner | lib_build
	@echo ""
	$(call pretty_header, 'Creating binary of : $(PROJECT)')
	@echo "$(BOLD)$(WHITE) done $(END)"
	$(call pretty_header, 'Successfully compiled $(PROJECT)!')

lib_build:
	@make -C lib/Cuddle

lib_build_debug:
	@make -C lib/Cuddle DEBUG=1

banner:
	@echo "$(PURPLE)  ____  _    _ _____ _      _____    ______     __   _____         _____ _    _                     ______ _______          __     _   _ ";
	@echo "$(CYAN) |  _ \\| |  | |_   _| |    |  __ \\  |  _ \\ \\   / /  / ____|  /\\   / ____| |  | |   /\\       ___    |  ____|  __ \\ \\        / /\\   | \\ | |";
	@echo "$(PURPLE) | |_) | |  | | | | | |    | |  | | | |_) \\ \\_/ /  | (___   /  \\ | |    | |__| |  /  \\     ( _ )   | |__  | |__) \\ \\  /\\  / /  \\  |  \\| |";
	@echo "$(CYAN) |  _ <| |  | | | | | |    | |  | | |  _ < \\   /    \\___ \\ / /\\ \\| |    |  __  | / /\\ \\    / _ \\/\\ |  __| |  _  / \\ \\/  \\/ / /\\ \\ | . \` |";
	@echo "$(PURPLE) | |_) | |__| |_| |_| |____| |__| | | |_) | | |     ____) / ____ \\ |____| |  | |/ ____ \\  | (_>  < | |____| | \\ \\  \\  /\\  / ____ \\| |\\  |";
	@echo "$(CYAN) |____/ \\____/|_____|______|_____/  |____/  |_|    |_____/_/    \\_\\_____|_|  |_/_/    \\_\\  \\___/\\/ |______|_|  \\_\\  \\/  \\/_/    \\_\\_| \\_|";
	@echo "$(PURPLE)                                                                                                                                                                   ";
	@echo "$(CYAN)                                                                                                                                                                   ";

manu_test:
	$(call pretty_header, 'Compiling : $(PROJECT)')
	@$(ECC) -o $(NAME) $(SRCMANU) $(LIBSFLAGS)

run:
	@$(ECC) -o $(NAME) $(SRCMANU) -L ./lib -I ./include -lcuddle -g3 $(MATHSFLAGS)
	$(call pretty_header, 'Running : $(PROJECT)')
	@./$(NAME) $(ARGUMENTS)

debug: fclean lib_build_debug
	$(call pretty_header, 'Compiling with debug flag for : $(PROJECT)')
	@$(ECC) -o $(NAME) $(SRCMANU) -L ./lib -I ./include -lcuddle -g3 $(NCURSESFLAGS) $(MATHSFLAGS)
	@echo "$(BOLD)$(WHITE) done $(END)"
	@echo ""
	@echo "$(BOLD)$(H_GREEN)✅ Debug build ready! Time to hunt bugs! 🎯$(END)"
	@echo ""
	@echo "$(H_PURPLE)🔍 Running Valgrind memory check...$(END)"
	@mkdir -p Logs
	@valgrind --leak-check=full \
    	--show-leak-kinds=all \
    	--track-origins=yes \
    	--log-file=Logs/valgrind.log \
		./$(NAME)
	@echo "$(H_CYAN)📝 Valgrind report saved to $(H_YELLOW)Logs/valgrind.log$(END)"
	@echo ""
	@if grep -q "ERROR SUMMARY: 0 errors" Logs/valgrind.log; then \
    	echo "$(BOLD)$(H_GREEN)✨ No memory errors detected! Perfect! ✨$(END)"; \
  	else \
    	echo "$(BOLD)$(H_YELLOW)⚠️  Memory issues detected! Check Logs/valgrind.log for details$(END)"; \
    fi
	@echo ""

unit_tests: re
	@$(MAKE) -C tests unit_tests

tests_run: re
	@$(MAKE) -C tests tests_run

coverage: re
	@$(MAKE) -C tests coverage

clean:
	$(call pretty_header, 'Cleaning object files')
	@$(RM) $(OBJMANU)
	@make clean -C lib/Cuddle/
	@make clean -C tests/

fclean: clean
	$(call pretty_header, 'Full clean: objects binary tests coverage')
	@$(RM) $(NAME) $(TO_RM) $(name)
	@make fclean -C lib/Cuddle/
	@make fclean -C tests/

re: fclean all

#──── optional ─────────────────────────────────────────────────────────────────
.PHONY: help
help:
	@echo ""
	@echo "$(BOLD)$(H_PURPLE)╔═══════════════════════════════════════════════════════════════╗$(END)"
	@echo "$(BOLD)$(H_PURPLE)║$(END)$(BOLD)$(H_WHITE)    Cuddle — DataFrame library for C  ·  Help Menu            $(END)"
	@echo "$(BOLD)$(H_PURPLE)╚═══════════════════════════════════════════════════════════════╝$(END)"
	@echo ""
	@echo "$(BOLD)$(H_CYAN)── Build ─────────────────────────────────────────────────────────$(END)"
	@echo "  $(BOLD)make$(END) / $(BOLD)make all$(END)          Build libcuddle (includes all utility functions) then link $(BOLD)$(NAME)$(END)"
	@echo "  $(BOLD)make manu_test$(END)           Quick one-shot compile of $(NAME) (no lib rebuild)"
	@echo "  $(BOLD)make run$(END) ARGUMENTS=\"\"   Run ./$(NAME) with optional runtime arguments"
	@echo "  $(BOLD)make debug$(END)               Debug build (-g3) + Valgrind full memory report"
	@echo ""
	@echo "$(BOLD)$(H_CYAN)── Tests & Coverage ──────────────────────────────────────────────$(END)"
	@echo "  $(BOLD)make unit_tests$(END)          Build Criterion unit-tests binary"
	@echo "  $(BOLD)make tests_run$(END)           Execute tests → logs saved in $(LOGS_DIR)/"
	@echo "  $(BOLD)make coverage$(END)            Execute tests → HTML report at $(COVERAGE_HTML)"
	@echo ""
	@echo "$(BOLD)$(H_CYAN)── Cleanup ───────────────────────────────────────────────────────$(END)"
	@echo "  $(BOLD)make clean$(END)               Remove .o files (project + both libs)"
	@echo "  $(BOLD)make fclean$(END)              Remove binaries, tests and coverage artefacts"
	@echo "  $(BOLD)make re$(END)                  Full rebuild (fclean + all)"
	@echo ""
	@echo "$(BOLD)$(H_CYAN)── libcuddle  ·  DataFrame API ───────────────────────────────────$(END)"
	@echo ""
	@echo "  $(BOLD)Core$(END)"
	@echo "    df_read_csv(file, sep)            Parse a CSV file into a $(BOLD)dataframe_t$(END)"
	@echo "                                     Auto-detects column types: bool/int/uint/float/string"
	@echo "    df_write_csv(df, file)            Serialize a $(BOLD)dataframe_t$(END) back to a CSV file"
	@echo ""
	@echo "  $(BOLD)Basics$(END)"
	@echo "    df_head(df, n)                   Return a new df with the first n data rows"
	@echo "    df_tail(df, n)                   Return a new df with the last n data rows"
	@echo "    df_shape(df)                     Return a $(BOLD)dataframe_shape_t$(END) {nb_rows, nb_columns}"
	@echo "    df_info(df)                      Print each column name and its inferred type"
	@echo "    df_describe(df)                  Print statistical summary per column  [stub]"
	@echo ""
	@echo "  $(BOLD)Filtering$(END)"
	@echo "    df_filter(df, col, fn)           Keep rows where fn(cell) == true  [stub]"
	@echo ""
	@echo "  $(BOLD)Sorting$(END)"
	@echo "    df_sort(df, col, cmp)            Sort rows by column using comparator cmp  [stub]"
	@echo ""
	@echo "  $(BOLD)Transformation$(END)"
	@echo "    df_apply(df, col, fn)            Apply fn to every cell of a column  [stub]"
	@echo "    df_to_type(df, col, type)        Cast a column to target type (BOOL/INT/UINT/FLOAT/STRING)  [stub]"
	@echo ""
	@echo "  $(BOLD)Aggregation$(END)"
	@echo "    df_groupby(df, by, cols[], fn)   Group rows by column, aggregate with fn  [stub]"
	@echo ""
	@echo "  $(BOLD)Utilities$(END)"
	@echo "    df_get_value(df, row, col)       Get the typed value at (row, column)"
	@echo "    df_get_values(df, col)           Get all typed values of a column  [stub]"
	@echo "    df_get_unique_values(df, col)    Get deduplicated typed values of a column  [stub]"
	@echo "    df_free(df)                      Recursively free all dataframe memory"
	@echo ""
	@echo "  $(BOLD)Types$(END)"
	@echo "    dataframe_t       void*** data  ·  nb_rows  ·  nb_columns  ·  separator"
	@echo "    infos_data_t      column header: name (char*) + inferred column_type_t"
	@echo "    column_type_t     BOOL · INT · UINT · FLOAT · STRING · UNDEFINED"
	@echo "    dataframe_shape_t {int nb_rows, int nb_columns}"
	@echo ""
	@echo "$(BOLD)$(H_CYAN)── Repository Layout ─────────────────────────────────────────────$(END)"
	@echo "  Src/            application entry point (main.c)"
	@echo "  lib/Cuddle/     libcuddle sources (Aggregation · Basics · Core ·"
	@echo "                                       Filtering · Sorting · Transformation · Utilities · all utility functions)"
	@echo "  include/        shared headers  (dataframe.h · my.h · linked_lists.h · defines.h …)"
	@echo "  tests/          Criterion unit tests + Makefile"
	@echo "  Logs/           build logs, valgrind report, coverage HTML"
	@echo "  Doc/            README · architecture diagram · policies"
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
