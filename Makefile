##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	src/printf/my_strlen.c	\
        src/printf/my_putchar.c	\
		src/printf/my_putstr.c	\
		src/printf/my_put_nbr.c	\
		src/printf/my_getnbr.c	\
		src/printf/my_strcmp.c	\
		src/printf/my_revstr.c	\
		src/printf/my_printf.c	\
		src/get_next_line.c	\
		src/my_path_to_word_array.c	\
		src/start_communication.c 	\
		src/error_handling_2.c	\
		src/signal_handlers.c	\
		src/handle_input.c	\
		src/create_map.c	\
		src/fill_maps.c	\
		src/map_handling.c	\
		src/error_handling.c	\
		src/turn_by_turn.c	\
		src/manage_shot.c 	\
		src/set_boat.c	\
		src/navy.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

CFLAGS	+=	-Wall -Wextra -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all