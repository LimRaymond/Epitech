##
## EPITECH PROJECT, 2018
## dasd
## File description:
## asd
##

NAME	=	philo

CC	=	gcc

RM	=	rm -f

SRCS	=	src/main.c          \
		src/display_help.c  \
		src/create_list.c   \
		src/game_process.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS =	-I./include
CFLAGS +=	-W -Wall -Wextra -g -Ofast

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS) -L. -lriceferee -lpthread

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
