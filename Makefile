##
## EPITECH PROJECT, 2023
## undefined
## File description:
## Makefile to compile files with the lib.
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

BIN_NAME	=	my_radar

CFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio	\
			-lcsfml-window -g3 -W -Wall

all:	compile_lib compile

compile_lib:
	make -C lib/my

compile:	$(OBJ)
	gcc -o $(BIN_NAME) $(OBJ) -L. -lmy -lm $(CFLAGS)
	mv $(OBJ) bin

clean:
	rm -f bin/*.o
	make clean -C lib/my

fclean:	clean
	rm -f $(BIN_NAME)
	make fclean -C lib/my

re:	fclean all
