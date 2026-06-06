##
## EPITECH PROJECT, 2025
## makefile
## File description:
## a make file that is able to do lots of things tests manual tests compiling coverage...
## see "make help"
##

MAKEFLAGS += --no-print-directory

# ─── Project Info ────────────────────────────────────────────────────────
 PROJECT = Corewar
 NAME	= corewar
 LIB_NAME = libmy.a

# ─── Sources ─────────────────────────────────────────────────────────────
SRCMANU =	Src/main.c \
	Src/puterr.c \
	Src/my_help.c \
	Src/corewar.c \
	Src/check_corewar.c \
	Src/is_cor_file.c \
	Src/is_flag.c \
	Src/is_visual_flag.c \
	Src/is_integer.c \
	Src/is_dump.c \
	Src/is_number.c \
	Src/is_address.c \
	Src/is_champion.c \
	Src/count_champions.c \
	Src/add_champion.c \
	Src/close_files.c \
	Src/is_files_open.c \
	Src/champions_alive.c \
	Src/corewar_loop.c \
	Src/corewar_period.c \
	Src/fill_prog.c \
	Src/init_vm.c \
	Src/write_hex.c \
	Src/write_address.c \
	Src/write_memory.c \
	Src/read_champ.c \
	Src/is_magic_number.c \
	Src/dump.c \
	Src/create_cursor.c \
	Src/move_cursor.c \
	Src/op.c \
	Src/instructions/memory_utils.c \
	Src/instructions/arg_utils.c \
	Src/instructions/register_utils.c \
	Src/instructions/live.c \
	Src/instructions/ld.c \
	Src/instructions/st.c \
	Src/instructions/add.c \
	Src/instructions/sub.c \
	Src/instructions/and.c \
	Src/instructions/or.c \
	Src/instructions/xor.c \
	Src/instructions/zjmp.c \
	Src/instructions/ldi.c \
	Src/instructions/sti.c \
	Src/instructions/fork_corewar.c \
	Src/instructions/lld.c \
	Src/instructions/lldi.c \
	Src/instructions/lfork.c \
	Src/instructions/print.c \
	Src/fill_champs_options.c \
	Src/get_instruction_size.c \
	Src/print_winner.c \
	Src/visual/visual_grid.c \
	Src/visual/visual_owner.c \
	Src/visual/visual_draw.c \
	Src/visual/visual_init.c \
	Src/visual/visual_loop.c \

# ─── Test sources are defined in tests/Makefile ──────────────────────────

# ─── Flags ───────────────────────────────────────────────────────────────
TESTSFLAGS = --coverage -lcriterion -lgcov
LIBSFLAGS = -L ./lib -I ./include -lmy -O3 -lncurses
DEBUGFLAGS = -L ./lib -I ./include -g3 -lmy -lm
GCOVRSTYLE = 'github.dark-green'
LOGS_DIR = Logs
COVERAGE_DIR = $(LOGS_DIR)/coverage
COVERAGE_RAW_DIR = $(COVERAGE_DIR)/raw
COVERAGE_HTML = $(COVERAGE_DIR)/index.html
WEBGCOVRFLAGS = --html-theme $(GCOVRSTYLE) --html --html-nested -o $(COVERAGE_HTML)
GCOVRFLAGS = --gcov-executable "llvm-cov-20 gcov" --exclude tests/
NCURSESFLAGS = -lncurses
MATHSFLAGS = -lm
LIBS = -L ./lib -I ./include -lmy -lncurses
CSFMLFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system

# ─── Tools ───────────────────────────────────────────────────────────────
RM = rm -rf
ECC = epiclang
CC = clang
ARGUMENTS =

# ─── random ───────────────────────────────────────────────────────────────
TO_RM = *.gcda *.gcno unit_tests testing testing *.html *.css *.log main Logs libcuddle.a *.cor
OBJMANU = $(SRCMANU:.c=.o)


%.o: %.c
	@printf "$(H_CYAN)Compiling$(END) $(BOLD)$<$(END) ... \n"
	@$(ECC) $(CFLAGS) -L./lib -I./include -Wno-unused-command-line-argument -c $< -o $@ 2>&1 > /dev/null && \
		printf "%b\n" "$(BOLD)$(H_GREEN)[ OK ]$(END)" || \
		(printf "%b\n" "$(BOLD)$(H_RED)[ FAIL ]$(END)" && $(ECC) -L./lib -I./include -Wno-unused-command-line-argument -c $< -o $@ && exit 1)

# ─── Macro: Fancy Header ─────────────────────────────────────────────────
define pretty_header
	@printf "%b\n" "$(BOLD)$(H_PURPLE)╔═══════════════════════════════════════════════════════════════╗$(END)"
	@printf "%b\n" "$(BOLD)$(H_PURPLE)║$(END)$(BOLD)$(WHITE)$(1)$(END)"
	@printf "%b\n" "$(BOLD)$(H_PURPLE)╚═══════════════════════════════════════════════════════════════╝$(END)"
endef

# ─── Rules ───────────────────────────────────────────────────────────────
.PHONY: all manu_test run debug unit_tests tests_run coverage functional_tests clean fclean re banner lib_build lib_build_debug
all:	$(NAME)

$(NAME): banner | lib_build
	@printf "\n"
	$(call pretty_header, 'Creating binary of : $(PROJECT)')
	@printf "%b\n" "$(BOLD)$(WHITE) done $(END)"
	$(call pretty_header, 'Successfully compiled $(PROJECT)!')
	@$(ECC) -o $(NAME) $(SRCMANU) $(LIBSFLAGS) $(CFLAGS)

lib_build:
	@make -C lib/My CFLAGS="$(CFLAGS)"

lib_build_debug:
	@make -C lib/My DEBUG=1

banner:
	@printf "%b\n" "$(PURPLE)                                                                   ";
	@printf "%b\n" "██████╗ ██╗   ██╗██╗██╗     ██████╗     ██████╗ ██╗   ██╗                ";
	@printf "%b\n" "██╔══██╗██║   ██║██║██║     ██╔══██╗    ██╔══██╗╚██╗ ██╔╝                ";
	@printf "%b\n" "██████╔╝██║   ██║██║██║     ██║  ██║    ██████╔╝ ╚████╔╝                 ";
	@printf "%b\n" "██╔══██╗██║   ██║██║██║     ██║  ██║    ██╔══██╗  ╚██╔╝                  ";
	@printf "%b\n" "██████╔╝╚██████╔╝██║███████╗██████╔╝    ██████╔╝   ██║                   ";
	@printf "%b\n" "╚═════╝  ╚═════╝ ╚═╝╚══════╝╚═════╝     ╚═════╝    ╚═╝                   ";
	@printf "%b\n" "                                                                         ";
	@printf "%b\n" "██████╗ ██╗   ██╗ ██████╗███████╗██████╗ ██╗  ██╗ █████╗ ██╗     ███████╗";
	@printf "%b\n" "██╔══██╗██║   ██║██╔════╝██╔════╝██╔══██╗██║  ██║██╔══██╗██║     ██╔════╝";
	@printf "%b\n" "██████╔╝██║   ██║██║     █████╗  ██████╔╝███████║███████║██║     █████╗  ";
	@printf "%b\n" "██╔══██╗██║   ██║██║     ██╔══╝  ██╔═══╝ ██╔══██║██╔══██║██║     ██╔══╝  ";
	@printf "%b\n" "██████╔╝╚██████╔╝╚██████╗███████╗██║     ██║  ██║██║  ██║███████╗███████╗";
	@printf "%b\n" "╚═════╝  ╚═════╝  ╚═════╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝";
	@printf "%b\n" "                                                                         ";

manu_test:
	$(call pretty_header, 'Compiling : $(PROJECT)')
	@$(ECC) -o $(NAME) $(SRCMANU) $(LIBSFLAGS)

run:
	@$(ECC) -o $(NAME) $(SRCMANU) -L ./lib -I ./include -lmy -g3 $(MATHSFLAGS)
	$(call pretty_header, 'Running : $(PROJECT)')
	@./$(NAME) $(ARGUMENTS)

debug: fclean lib_build_debug
	$(call pretty_header, 'Compiling with debug flag for : $(PROJECT)')
	@$(ECC) -o $(NAME) $(SRCMANU) -L ./lib -I ./include -lmy -g3 $(NCURSESFLAGS) $(MATHSFLAGS)
	@printf "%b\n" "$(BOLD)$(WHITE) done $(END)"
	@printf "\n"
	@printf "%b\n" "$(BOLD)$(H_GREEN)✅ Debug build ready! Time to hunt bugs! 🎯$(END)"
	@printf "\n"
	@printf "%b\n" "$(H_PURPLE)🔍 Running Valgrind memory check...$(END)"
	@mkdir -p Logs
	@valgrind --leak-check=full \
    	--show-leak-kinds=all \
    	--track-origins=yes \
    	--log-file=Logs/valgrind.log \
		./$(NAME) champions/pdd.s
	@printf "%b\n" "$(H_CYAN)📝 Valgrind report saved to $(H_YELLOW)Logs/valgrind.log$(END)"
	@printf "\n"
	@if grep -q "ERROR SUMMARY: 0 errors" Logs/valgrind.log; then \
    	printf "%b\n" "$(BOLD)$(H_GREEN)✨ No memory errors detected! Perfect! ✨$(END)"; \
  	else \
    	printf "%b\n" "$(BOLD)$(H_YELLOW)⚠️  Memory issues detected! Check Logs/valgrind.log for details$(END)"; \
    fi
	@printf "\n"

unit_tests: re
	@$(MAKE) -C tests unit_tests

tests_run: re
	@$(MAKE) -C tests tests_run

coverage: re
	@$(MAKE) -C tests coverage

clean:
	$(call pretty_header, 'Cleaning object files')
	@$(RM) $(OBJMANU)
	@make clean -C lib/My/
	@make clean -C tests/

fclean: clean
	$(call pretty_header, 'Full clean: objects binary tests coverage')
	@$(RM) $(NAME) $(TO_RM) $(name)
	@make fclean -C lib/My/
	@make fclean -C tests/

re: fclean all

#──── optional ─────────────────────────────────────────────────────────────────
.PHONY: help
help:
	@printf "\n"
	@printf "%b\n" "$(BOLD)$(H_PURPLE)╔═══════════════════════════════════════════════════════════════╗$(END)"
	@printf "%b\n" "$(BOLD)$(H_PURPLE)║$(END)$(BOLD)$(H_WHITE)    Cuddle — DataFrame library for C  ·  Help Menu            $(END)"
	@printf "%b\n" "$(BOLD)$(H_PURPLE)╚═══════════════════════════════════════════════════════════════╝$(END)"
	@printf "\n"
	@printf "%b\n" "$(BOLD)$(H_CYAN)── Build ─────────────────────────────────────────────────────────$(END)"
	@printf "%b\n" "  $(BOLD)make$(END) / $(BOLD)make all$(END)          Build libcuddle (includes all utility functions) then link $(BOLD)$(NAME)$(END)"
	@printf "%b\n" "  $(BOLD)make manu_test$(END)           Quick one-shot compile of $(NAME) (no lib rebuild)"
	@printf "%b\n" "  $(BOLD)make run$(END) ARGUMENTS=\"\"   Run ./$(NAME) with optional runtime arguments"
	@printf "%b\n" "  $(BOLD)make debug$(END)               Debug build (-g3) + Valgrind full memory report"
	@printf "\n"
	@printf "%b\n" "$(BOLD)$(H_CYAN)── Tests & Coverage ──────────────────────────────────────────────$(END)"
	@printf "%b\n" "  $(BOLD)make unit_tests$(END)          Build Criterion unit-tests binary"
	@printf "%b\n" "  $(BOLD)make tests_run$(END)           Execute tests → logs saved in $(LOGS_DIR)/"
	@printf "%b\n" "  $(BOLD)make coverage$(END)            Execute tests → HTML report at $(COVERAGE_HTML)"
	@printf "\n"
	@printf "%b\n" "$(BOLD)$(H_CYAN)── Cleanup ───────────────────────────────────────────────────────$(END)"
	@printf "%b\n" "  $(BOLD)make clean$(END)               Remove .o files (project + both libs)"
	@printf "%b\n" "  $(BOLD)make fclean$(END)              Remove binaries, tests and coverage artefacts"
	@printf "%b\n" "  $(BOLD)make re$(END)                  Full rebuild (fclean + all)"
	@printf "\n"
	@printf "%b\n" "$(BOLD)$(H_CYAN)── libcuddle  ·  DataFrame API ───────────────────────────────────$(END)"
	@printf "\n"
	@printf "%b\n" "  $(BOLD)Core$(END)"
	@printf "%b\n" "    df_read_csv(file, sep)            Parse a CSV file into a $(BOLD)dataframe_t$(END)"
	@printf "%b\n" "                                     Auto-detects column types: bool/int/uint/float/string"
	@printf "%b\n" "    df_write_csv(df, file)            Serialize a $(BOLD)dataframe_t$(END) back to a CSV file"
	@printf "\n"
	@printf "%b\n" "  $(BOLD)Basics$(END)"
	@printf "%b\n" "    df_head(df, n)                   Return a new df with the first n data rows"
	@printf "%b\n" "    df_tail(df, n)                   Return a new df with the last n data rows"
	@printf "%b\n" "    df_shape(df)                     Return a $(BOLD)dataframe_shape_t$(END) {nb_rows, nb_columns}"
	@printf "%b\n" "    df_info(df)                      Print each column name and its inferred type"
	@printf "%b\n" "    df_describe(df)                  Print statistical summary per column  [stub]"
	@printf "\n"
	@printf "%b\n" "  $(BOLD)Filtering$(END)"
	@printf "%b\n" "    df_filter(df, col, fn)           Keep rows where fn(cell) == true  [stub]"
	@printf "\n"
	@printf "%b\n" "  $(BOLD)Sorting$(END)"
	@printf "%b\n" "    df_sort(df, col, cmp)            Sort rows by column using comparator cmp  [stub]"
	@printf "\n"
	@printf "%b\n" "  $(BOLD)Transformation$(END)"
	@printf "%b\n" "    df_apply(df, col, fn)            Apply fn to every cell of a column  [stub]"
	@printf "%b\n" "    df_to_type(df, col, type)        Cast a column to target type (BOOL/INT/UINT/FLOAT/STRING)  [stub]"
	@printf "\n"
	@printf "%b\n" "  $(BOLD)Aggregation$(END)"
	@printf "%b\n" "    df_groupby(df, by, cols[], fn)   Group rows by column, aggregate with fn  [stub]"
	@printf "\n"
	@printf "%b\n" "  $(BOLD)Utilities$(END)"
	@printf "%b\n" "    df_get_value(df, row, col)       Get the typed value at (row, column)"
	@printf "%b\n" "    df_get_values(df, col)           Get all typed values of a column  [stub]"
	@printf "%b\n" "    df_get_unique_values(df, col)    Get deduplicated typed values of a column  [stub]"
	@printf "%b\n" "    df_free(df)                      Recursively free all dataframe memory"
	@printf "\n"
	@printf "%b\n" "  $(BOLD)Types$(END)"
	@printf "%b\n" "    dataframe_t       void*** data  ·  nb_rows  ·  nb_columns  ·  separator"
	@printf "%b\n" "    infos_data_t      column header: name (char*) + inferred column_type_t"
	@printf "%b\n" "    column_type_t     BOOL · INT · UINT · FLOAT · STRING · UNDEFINED"
	@printf "%b\n" "    dataframe_shape_t {int nb_rows, int nb_columns}"
	@printf "\n"
	@printf "%b\n" "$(BOLD)$(H_CYAN)── Repository Layout ─────────────────────────────────────────────$(END)"
	@printf "%b\n" "  Src/            application entry point (main.c)"
	@printf "%b\n" "  lib/My/     libcuddle sources (Aggregation · Basics · Core ·"
	@printf "%b\n" "                                       Filtering · Sorting · Transformation · Utilities · all utility functions)"
	@printf "%b\n" "  include/        shared headers  (dataframe.h · my.h · linked_lists.h · defines.h …)"
	@printf "%b\n" "  tests/          Criterion unit tests + Makefile"
	@printf "%b\n" "  Logs/           build logs, valgrind report, coverage HTML"
	@printf "%b\n" "  Doc/            README · architecture diagram · policies"
	@printf "\n"


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
