##
## Makefile for header in /home/duez_a//my_ftp
## 
## Made by guillaume duez
## Login   <duez_a@epitech.net>
## 
## Started on  Mon Feb  4 12:48:16 2013 guillaume duez
## Last update Mon May 27 15:57:52 2013 guillaume duez
##

SERV	=	serveur

SRC_SERV=	serveur.c		\
		client_utils.c		\
		tools/tools_socket.c	\
		send_receiv.c		\
		action.c		\
		tools/xmalloc.c

OBJ_SERV=	$(SRC_SERV:.c=.o)

CC      = gcc

CFLAGS  = -Wall -W -Wextra

RM      = rm -f


all: $(CLI) $(SERV)

$(SERV): $(OBJ_SERV)
	$(CC) -o $(SERV) $(OBJ_SERV)

clean   :
	$(RM) $(OBJ_CLI) $(OBJ_SERV)

fclean	:
	$(RM) $(OBJ_CLI) $(OBJ_SERV) $(CLI) $(SERV)

re      : clean all