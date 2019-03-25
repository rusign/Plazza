##
## Makefile for  in /home/mart_4/BEFORE_PUSH/QT/cpp_plazza/QTPlazza
##
## Made by mart_4
## Login   <mart_4@epitech.net>
##
## Started on  Sun Apr 24 22:51:21 2016 mart_4
## Last update Sun Apr 24 22:54:39 2016 mart_4
##

NAME		=	QTplazza

SRC		=	mainwindow.cpp\
			main.cpp\
			moc_mainwindow.cpp\

OBJ		=	$(SRC:.cpp=.o)

RM		=	rm -rf

CC		=	g++

INCFLAGS        =       -I. -isystem /usr/include/qt -isystem /usr/include/qt/QtCore -isystem /usr/include/qt/QtGui -isystem /usr/include/qt/QtWidgets

CXXFLAGS        =       -W -Wall -fPIC $(INCFLAGS) -g3 -std=c++11

LDFLAGS         =       -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread 


all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all re clean fclean
