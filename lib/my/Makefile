##
## EPITECH PROJECT, 2021
## Stumper 3 makefile lib
## File description:
## Makefile lib
##

SRC 	=	my_getnbr.c \
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

OBJ 	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) *.o

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
