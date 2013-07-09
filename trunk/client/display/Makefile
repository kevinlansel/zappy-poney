##
## Makefile for Client in /home/haz3/projet/zappy-poney/client/CouillePutePlus
## 
## Made by Maxime Wojciak
## Login   <wojcia_m@epitech.net>
## 
## Started on  Thu Jun 27 17:33:04 2013 Maxime Wojciak
## Last update Tue Jul  9 15:57:37 2013 Maxime Wojciak
##

NAME=		Display

SRC=		Audio.cpp		\
		Case.cpp		\
		get_next_line.cpp	\
		main.cpp		\
		Network.cpp		\
		Personnage.cpp		\
		Player.cpp		\
		Souris.cpp		\
		Texture.cpp		\
		Windows.cpp		\
		Message.cpp		\
		pouet.cpp

OBJ=		$(SRC:.cpp=.o)

CC=		g++

CXXFLAGS=	-W -Wall -Wextra

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -ggdb3

all:		$(NAME)

clean:
		rm -vf $(OBJ)

fclean:		clean
		rm -vf $(NAME)

re:		fclean all
