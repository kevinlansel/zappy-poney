NAME_DISP=	display

SRC_DISP=	Network_display.cpp \
		get_next_line.cpp \
		main.cpp

OBJ_DISP=	$(SRC_DISP:.cpp=.o)

all:		$(OBJ_DISP)
		g++ -o $(NAME_DISP) $(OBJ_DISP)

clean:
		rm -f $(OBJ_DISP)

fclean:		clean
		rm -f $(NAME_DISP)

re:		fclean all