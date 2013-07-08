##
## Makefile for header in /home/duez_a//my_ftp
## 
## Made by guillaume duez
## Login   <duez_a@epitech.net>
## 
## Started on  Mon Feb  4 12:48:16 2013 guillaume duez
## Last update Mon Jul  8 16:06:22 2013 guillaume duez
##

SERV	=	serveur

SRC_SERV=	action.c			\
		calculator.c			\
		cmd.c				\
		client.c			\
		client_utils.c			\
		connexion.c			\
		dialog_client/check_msg_srv.c	\
		dialog_client/egg.c		\
		dialog_client/level.c		\
		dialog_client/map_func.c	\
		dialog_client/player_action.c	\
		dialog_client/player_func.c	\
		dialog_client/player_ress.c	\
		dialog_client/serv_func.c	\
		dialog_client/utils_protocol.c	\
		echo.c				\
		expulse.c			\
		fork.c				\
		init.c				\
		init_map.c			\
		level_up.c			\
		main.c				\
		map_utils.c			\
		msg.c				\
		parse_conf.c			\
		send_receiv.c			\
		serveur.c			\
		take_let.c			\
		task_time_client.c		\
		task_utils.c			\
		tools/str_to_word.c		\
		tools/tools_socket.c		\
		tools/xmalloc.c			\
		vision.c

OBJ_SERV=	$(SRC_SERV:.c=.o)

CC	=	 gcc -g

CFLAGS	=	 -Wall -W -Wextra -lm

RM	=	 rm -f


all:		$(SERV)

$(SERV):	$(OBJ_SERV)
		$(CC) -o $(SERV) $(OBJ_SERV) -lm

clean	:
		$(RM) $(OBJ_CLI) $(OBJ_SERV)

fclean	:
		$(RM) $(OBJ_CLI) $(OBJ_SERV) $(CLI) $(SERV)

re	:	clean all

.PHONY	:	all clean fclean re