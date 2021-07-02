##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## compile
##

MAIN	=		src/main.c

SRC		=		src/set_up_connection.c	\
				src/navy.c				\
				src/data_transfer.c		\
				src/end_game.c			\
				src/error_handling.c	\
				src/init_game.c

TESTS 	=		tests/test_my_errors_test.c

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o)

NAME	=		navy

LIB		=		lib/libmy.a

CFLAGS 	=		-W -Wall -Wextra -g

CPPFLAGS	=	-I./include

LDFLAGS	=	-Llib/

LDIBS	=	-lmy

all:		$(NAME)

$(NAME):	$(OBJ) $(LIB)
			gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDIBS)
			make clean

$(LIB):
			make -C lib/my

tests_run:	LDIBS += -lcriterion --coverage
tests_run:	all
			gcc -o $@ $(SRC) $(TESTS) $(CPPFLAGS) $(LDFLAGS) $(LDIBS)
			-./$@
			$(RM) *.gc*
			$(RM) $@

clean:
		$(RM) -f src/*.o
		$(RM) *~
		$(RM) *.gc*

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(LIB)
		make -C lib/my fclean

re:		fclean all