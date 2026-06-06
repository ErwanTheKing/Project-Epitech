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
SRC = ../main.c \
	  ../main/main_menu.c \
	  ../main/button_main.c \
	  ../main/execute_main.c  \
	  ../main/text_main.c \
	  ../settings/settings_menu.c \
	  ../settings/button_settings.c \
	  ../settings/button_settings2.c \
      ../settings/text_settings.c \
      ../settings/execute_settings.c \
      ../settings/execute_settings2.c \
      ../pause/pause_menu.c \
      ../pause/button_pause.c \
      ../pause/execute_pause.c \
      ../game/manage_sprite.c \
	  ../game/$(NAME).c \
	  ../game/execute_hunter.c \
	  ../game/text_game.c \
      ../game/sprite_hunter.c \
      ../game/destroy_sprite.c \
      ../game/draw_sprite.c \
      ../game/ammo_sprite.c \
      ../loose/loose_menu.c \
      ../loose/sprite_loose.c \
      ../chose_mode/chose_mode.c \
      ../chose_mode/sprite_chose_mode.c

# ─── Flags ───────────────────────────────────────────────────────────────
CSFML = -I../include
CFLAGS = -Wextra -Wall
CSFML += -Wno-deprecated-declarations -Wno-error=deprecated-declarations

# ─── Tools ───────────────────────────────────────────────────────────────
RM = rm -rf
CC = clang
OBJ = $(SRC:.c=.o)

CFLAGS += -I/opt/homebrew/include -L/opt/homebrew/lib -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

.PHONY: all clean fclean re

# ─── Rules ───────────────────────────────────────────────────────────────
all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) -o ../$(NAME) $(OBJ) $(CSFML) $(CFLAGS)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) ../$(NAME) *.gcda *.gcno unit_tests testing testing *.html *.css *.log

re: fclean all