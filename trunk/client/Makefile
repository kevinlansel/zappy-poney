##
## Makefile for zappy in /home/peelou/SVN/zappy-poney/client
## 
## Made by gery baudry
## Login   <baudry_g@epitech.net>
## 
## Started on  Wed Jul  3 10:29:09 2013 gery baudry
## Last update Wed Jul  3 10:29:11 2013 gery baudry
##

NAME_DISP=	display

NAME_CLIENT=	client

SRC_DISP=	display_dir/Network_display.cpp \
		display_dir/get_next_line.cpp \
		display_dir/main.cpp

SRC_CLIENT=	main.cpp

OBJ_DISP=	$(SRC_DISP:.cpp=.o)

OBJ_CLIENT=	$(SRC_CLIENT:.cpp=.o)

all:		$(OBJ_DISP) $(OBJ_CLIENT)
		g++ -o $(NAME_DISP) $(OBJ_DISP)
		g++ -o $(NAME_CLIENT) $(OBJ_CLIENT) -lpthread

clean:
		rm -f $(OBJ_DISP) $(OBJ_CLIENT)

fclean:		clean
		rm -f $(NAME_DISP)
		rm -f $(NAME_CLIENT)

re:		fclean all