##
## EPITECH PROJECT, 2023
## undefined
## File description:
## Makefile for mylib
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

LIB_NAME	=	libmy.a

H_NAME	=	my.h

all:	lib copy_header

lib: create_lib copy_lib

create_lib:	$(OBJ)
	ar rc $(LIB_NAME) $(OBJ)

copy_lib:
	cp $(LIB_NAME) ../..

copy_header:
	cp $(H_NAME) ../../include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(LIB_NAME) ../../$(LIB_NAME)

re:	fclean all
