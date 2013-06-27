##
## Makefile for Client in /home/haz3/projet/zappy-poney/client/CouillePutePlus
## 
## Made by Maxime Wojciak
## Login   <wojcia_m@epitech.net>
## 
## Started on  Thu Jun 27 17:33:04 2013 Maxime Wojciak
## Last update Thu Jun 27 18:17:36 2013 Maxime Wojciak
##

NAME=		client

SRC=		Windows.cpp	\
		main.cpp

OBJ=		$(SRC:.cpp=.o)

CC=		g++

SFML=		-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

#CXXFLAGS=	-W -Wall -Wextra

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(SFML)

all:		$(NAME)

clean:
		rm -vf $(OBJ)

fclean:		clean
		rm -vf $(NAME)

re:		fclean all
