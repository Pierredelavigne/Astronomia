##
## EPITECH PROJECT, 2021
## Stumper 3 makefile lib
## File description:
## Makefile lib
##

# Allow overriding CC from parent Makefile or environment
CC ?= gcc
AR ?= ar
RM ?= rm -f

SRC 	=	my_getnbr.c \
			my_putchar.c \
			my_putstr.c \
			my_putstr_error.c \
			str_append.c \
			my_strlen.c \
			my_compute_power_rec.c \
			my_strcat.c \
			my_strdup.c \
			my_strcmp.c \
			str_match.c \
			nb_to_str.c \
			char_to_end_of_str.c \
			load_file_in_mem.c \
			# my_show_word_array.c # Example if this file exists and is part of lib
			# print_double_array.c # Example
			# Add other .c files from lib/my that are part of the library

OBJ 	=	$(SRC:.c=.o)

# CFLAGS for the library itself, can be minimal
# Or inherit CFLAGS from parent if needed for consistency (e.g., -Wall)
# For now, let the default CFLAGS of the compiler be used, or specify basic ones.
MY_CFLAGS ?= -Wall -Wextra -I../../include # Include path to my.h if lib sources need it

NAME	=	libmy.a

all: $(NAME)

%.o: %.c
	$(CC) $(MY_CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	# ranlib $(NAME) # Good practice, though often not strictly needed with GNU ar

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
