##
## Makefile for Makefile in /home/gfischer/Downloads/n4s_package
## 
## Made by Guillaume Fischer
## Login   <gfischer@epitech.net>
## 
## Started on  Tue May  9 17:49:26 2017 Guillaume Fischer
## Last update Thu Jun  1 13:53:28 2017 LIM Raymond
##

SRC	=	src/main.c			\
		src/car_setting.c		\
		src/my_strtab.c		\
		src/get_next_line.c

NAME	=	ai

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include/

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
