##
## Makefile for Makefile in /home/tchikl_h/rendu/B2/Infography/gfx_game_of_life
## 
## Made by Hervé TCHIKLADZE
## Login   <tchikl_h@epitech.net>
## 
## Started on  Thu Apr 28 17:07:49 2016 Hervé TCHIKLADZE
## Last update Tue May  3 15:25:14 2016 Hervé TCHIKLADZE
##

NAME		=	game_of_life

CC		=	gcc -g

RM		=	rm -rf

LIB		=	-L/home/${USER}/.froot/lib/		\
			-llapin     				\
	                -L/usr/local/lib                        \
		        -lsfml-audio                            \
	                -lsfml-graphics                         \
		        -lsfml-window                           \
			-lsfml-system                           \
	                -lstdc++				\
			-ldl					\
		        -lm                                     \


CFLAGS		=	-W				\
			-Wall				\
			-Werror				\
			-Wextra			 	\
			-I				\
			./include/			\

MAIN		=	./sources/main/

MYLIB		=	./sources/mylib/

DISPLAY		=	./sources/display/

GAME		=	./sources/game/

SRC		=	$(MAIN)main.c			\
			$(DISPLAY)display.c		\
			$(GAME)game.c			\
			$(MYLIB)tekpixel.c		\
			$(MYLIB)teksquare.c		\
			$(MYLIB)my_free.c		\

OBJS		=	$(SRC:.c=.o)


all		:	$(OBJS)
			$(CC) -g $(OBJS) -o $(NAME) $(LIB)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
