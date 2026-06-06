MAKEFLAGS += --no-print-directory

# ─── Project Info ────────────────────────────────────────────────────────
NAME = libmy.a

# ─── Sources ─────────────────────────────────────────────────────────────
SRC	=   printing/my_put_nbr.c \
		printing/my_putchar.c \
		printing/my_putnbr_base.c \
		printing/my_putstr.c \
		printing/my_str_isprintable.c \
		printing/my_show_word_array.c \
		opperations/cmp_alpha.c \
		opperations/my_compute_power_rec.c \
		opperations/my_compute_square_root.c \
		opperations/my_strcmp.c \
		opperations/my_strncmp.c \
		opperations/minimum_int_from_list.c \
		opperations/sort_word_array.c \
		opperations/my_swap.c \
		opperations/my_isneg.c \
		opperations/my_is_prime.c \
		opperations/my_array_len.c \
		opperations/my_char_isnum.c \
		opperations/my_find_prime_sup.c \
		opperations/my_getnbr.c \
		opperations/len_nb.c \
		manage_str/my_nbr_to_str.c \
		manage_str/my_revstr.c \
		manage_str/my_str_isalpha.c \
		manage_str/my_str_islower.c \
		manage_str/my_str_isnum.c \
		manage_str/my_str_isupper.c \
		manage_str/my_str_to_word_array.c \
		manage_str/my_strcapitalize.c \
		manage_str/my_strconcat.c \
		manage_str/my_strcpy.c \
		manage_str/my_strlen.c \
		manage_str/my_strlowcase.c \
		manage_str/my_strncat.c \
		manage_str/my_strncpy.c \
		manage_str/my_strstr.c \
		manage_str/my_strupcase.c \
		manage_str/my_array_len.c \
		malloc/free_array.c \
		malloc/get_file_size_nostat.c \
		malloc/get_file_size_stat.c \
		malloc/my_strndup.c \
		malloc/my_strdup.c \
		malloc/openator.c \
		malloc/my_char_array_dup.c \
		malloc/free_all.c \
		linked_lists/free_list.c \
		linked_lists/get_at.c \
		linked_lists/get_back.c \
		linked_lists/get_front.c \
		linked_lists/insert_node.c \
		linked_lists/list_len.c \
		linked_lists/pop_at.c \
		linked_lists/pop_back.c \
		linked_lists/pop_front.c \
		linked_lists/push_back.c \
		linked_lists/push_front.c \
		linked_lists/search_in_list.c

# ─── Tools ───────────────────────────────────────────────────────────────
OBJ = $(SRC:.c=.o)
RM  = rm -rf

UNAME_S := $(shell uname -s)

CC  ?= gcc
ECC ?= epiclang

ifeq ($(UNAME_S),Darwin)
	COMPILER := $(CC)
else
	COMPILER := $(ECC)
endif

%.o: %.c
	@printf "$(H_BLUE)⚡ $(BOLD)Compiling lib:$(END) $(H_YELLOW)%-45s$(END) $(H_GREEN)[OK]$(END)\r" $<
	@$(COMPILER) -L../lib -lmy -Wno-unused-command-line-argument -c $< -o $@

# ─── Macro: Fancy Header ─────────────────────────────────────────────────
define pretty_header
	@echo "$(BOLD)$(H_PURPLE)╔═══════════════════════════════════════════════════════════════╗$(END)"
	@echo "$(BOLD)$(H_PURPLE)║$(END)$(BOLD)$(WHITE)$(1)$(END)"
	@echo "$(BOLD)$(H_PURPLE)╚═══════════════════════════════════════════════════════════════╝$(END)"
endef

# ─── Rules ───────────────────────────────────────────────────────────────
all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@printf "                                                                       \r"
	@echo "$(BOLD)$(WHITE) done $(END)"
	$(call pretty_header, 🚀 copying libs 🚀)
	@cp $(NAME) ../
	@mkdir -p ../../include/
	@cp headers/*.h ../../include/
	@echo "$(BOLD)$(WHITE) done $(END)"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) ../$(NAME)
	@$(RM) -r ../../include

re: fclean all

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
