NAME_DISP=	display

NAME_CLIENT=	client

SRC_DISP=	display_dir/Network_display.cpp \
		display_dir/get_next_line.cpp \
		display_dir/main.cpp

SRC_CLIENT=	main.cpp

OBJ_DISP=	$(SRC_DISP:.cpp=.o)

OBJ_DISP=	$(SRC_CLIENT:.cpp=.o)

all:		$(OBJ_DISP)
		$(OBJ_CLIENT)
		g++ -o $(NAME_DISP) $(OBJ_DISP)
		g++ -o $(NAME_CLIENT) $(OBJ_CLIENT)

clean:
		rm -f $(OBJ_DISP)
		rm -f $(OBJ_CLIENT)

fclean:		clean
		rm -f $(NAME_DISP)
		rm -f $(NAME_CLIENT)

re:		fclean all