##
## EPITECH PROJECT, 2021
## B-MUL-100-RUN-1-1-myrunner-junot-hery-nantenaina.montpre
## File description:
## Makefile
##

SRC			= 	$(wildcard *.c)

CFLAGS		=	-W -Werror -Wextra -Wall -g3

IFLAGS		=	-I include/

LFLAGS		=	-L lib -lmy

NAME		=	bsq

all:
	make -C lib/my all
	gcc -o $(NAME) $(SRC) $(IFLAGS) $(CFLAGS) $(LFLAGS)

clean:
	make -C lib/my clean
	rm -f *~
	rm -f *gcda
	rm -f *gcno

fclean:	clean
	make -C lib/my fclean
	rm -f $(NAME)
	rm -f unit_tests

tests_run: re
	gcc -o unit_tests $(wildcard lib/my/*.c) $(wildcard tests/*.c) -lcriterion --coverage $(IFLAGS) $(LFLAGS)
	./unit_tests --verbose
	gcovr

re: fclean all
	make -C lib/my re
