##
## Makefile for  in /home/lund/Projets/zappy-poney/test
## 
## Made by florian dewulf
## Login   <dewulf_f@epitech.net>
## 
## Started on  Tue Jul 16 13:09:12 2013 florian dewulf
## Last update Tue Jul 16 14:47:22 2013 florian dewulf
##

NAME=		Display

SRC=		Case.cpp		\
		Core.cpp		\
		Except.cpp		\
		get_next_line.cpp	\
		Interpret.cpp		\
		main.cpp		\
		Memory.cpp		\
		Message.cpp		\
		Network.cpp		\
		Oeuf.cpp		\
		Player.cpp

OBJ=		$(SRC:.cpp=.o)

CXXFLAGS=	-W -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
