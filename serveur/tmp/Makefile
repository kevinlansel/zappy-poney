##
## Makefile for header in /home/duez_a//my_ftp
## 
## Made by guillaume duez
## Login   <duez_a@epitech.net>
## 
## Started on  Mon Feb  4 12:48:16 2013 guillaume duez
## Last update Fri Jun 14 11:06:13 2013 florian dewulf
##

SERV	=	serveur

SRC_SERV=	serveur.c		\
		main.c			\
		cmd.c			\
		client_utils.c		\
		map_utils.c		\
		tools/tools_socket.c	\
		send_receiv.c		\
		action.c		\
		vision.c		\
		task_utils.c		\
		init_map.c		\
		parse_conf.c		\
		echo.c			\
		tools/xmalloc.c

OBJ_SERV=	$(SRC_SERV:.c=.o)

CC      = gcc -g

CFLAGS  = -Wall -W -Wextra

RM      = rm -f


all: $(CLI) $(SERV)

$(SERV): $(OBJ_SERV)
	$(CC) -o $(SERV) $(OBJ_SERV) -lm

clean   :
	$(RM) $(OBJ_CLI) $(OBJ_SERV)

fclean	:
	$(RM) $(OBJ_CLI) $(OBJ_SERV) $(CLI) $(SERV)

re      : clean all