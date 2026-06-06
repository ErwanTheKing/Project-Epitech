##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##
MAKEFLAGS += --no-print-directory

# ─── Project Info ────────────────────────────────────────────────────────
NAME = libmy.a

# ─── Sources ─────────────────────────────────────────────────────────────
SRC	= print/my_putchar.c \
	manage_str/my_str_to_word_array.c \
    print/my_put_float.c \
    print/my_put_nbr.c \
    print/my_putnbr_base.c \
    print/my_putstr.c \
    print/my_show_word_array.c \
    print/my_str_isprintable.c \
    string/my_char_isnum.c \
    string/my_nbr_to_str.c \
    string/my_revstr.c \
    string/my_str_isalpha.c \
    string/my_str_isfloat.c \
    string/my_str_islower.c \
    string/my_str_isnegnum.c \
    string/my_str_isnum.c \
    string/my_str_isupper.c \
    string/my_strcapitalize.c \
    string/my_strconcat.c \
    string/my_strcpy.c \
    string/my_strlen.c \
    string/my_strlowcase.c \
    string/my_strncat.c \
    string/my_strncpy.c \
    string/my_strcmp.c \
    string/my_strncmp.c \
    string/my_strstr.c \
    string/my_strupcase.c \
    math/len_nb.c \
    math/minimum_int_from_list.c \
    math/my_compute_power_rec.c \
    math/my_compute_square_root.c \
    math/my_find_prime_sup.c \
    math/my_getnbr.c \
    math/my_is_prime.c \
    math/my_isneg.c \
    math/my_sort_int_array.c \
    math/my_swap.c \
    array/cmp_alpha.c \
    array/my_array_len.c \
    array/my_char_array_dup.c \
    array/sort_word_array.c \
    memory/free_all.c \
    memory/free_array.c \
    memory/my_strdup.c \
    memory/my_strndup.c \
    io/get_file_size_nostat.c \
    io/get_file_size_stat.c \
    io/openator.c \
    list/attach_list_to_back.c \
    list/free_list.c \
    list/get_at.c \
    list/get_back.c \
    list/get_front.c \
    list/get_to_middle.c \
    list/init_list.c \
    list/insert_node.c \
    list/invert_list.c \
    list/list_len.c \
    list/merge_sort_merge_list.c \
    list/merge_sort_split_lists.c \
    list/my_linked_list_to_word_array.c \
    list/my_wordarray_to_linked_list.c \
    list/pop_at.c \
    list/pop_back.c \
    list/pop_front.c \
    list/push_back.c \
    list/push_front.c \
    list/search_in_list.c

# ─── Tools ───────────────────────────────────────────────────────────────
OBJ	= $(SRC:.c=.o)
RM = rm -rf
ECC = epiclang

ifdef DEBUG
	OPTFLAGS = -g3
else ifndef CFLAGS
	OPTFLAGS = -O3
else
	OPTFLAGS =
endif

%.o: %.c
	@printf "$(H_BLUE)⚡ $(BOLD)Compiling lib:$(END) $(H_YELLOW)%-45s$(END) $(H_GREEN)[OK]$(END)\r" $<
	@$(ECC) $(CFLAGS) -L../lib -lmy -Wno-unused-command-line-argument -lm $(OPTFLAGS) -c $< -o $@

# ─── Macro: Fancy Header ─────────────────────────────────────────────────
define pretty_header
	@printf "%b\n" "$(BOLD)$(H_PURPLE)╔═══════════════════════════════════════════════════════════════╗$(END)"
	@printf "%b\n" "$(BOLD)$(H_PURPLE)║$(END)$(BOLD)$(WHITE)$(1)$(END)"
	@printf "%b\n" "$(BOLD)$(H_PURPLE)╚═══════════════════════════════════════════════════════════════╝$(END)"
endef

# ─── Rules ───────────────────────────────────────────────────────────────
all:	$(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@printf "                                                                       \r"
	@printf "%b\n" "$(BOLD)$(WHITE) done $(END)"
	$(call pretty_header, 🚀 copying libs 🚀)
	@cp $(NAME) ../
	@mkdir -p ../../include
	@cp ../Headers/*.h ../../include/
	@printf "%b\n" "$(BOLD)$(WHITE) done $(END)"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) ../$(NAME)
	@$(RM) -rf ../../include

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
