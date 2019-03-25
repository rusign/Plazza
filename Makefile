SRC = 	src/Core/Core.cpp \
	src/Parsing/Parsing.cpp \
	src/Commander/Commander.cpp \
	src/main.cpp \
	src/Core/Decipher/Regex.cpp \
	src/Encapsulate/NamedPipeInput.cpp \
	src/Encapsulate/NamedPipeOutput.cpp \
	src/Encapsulate/ManageThread.cpp \
	src/Encapsulate/ManageProcess.cpp \
	src/Encapsulate/ManangeOrder.cpp \
	src/Encapsulate/NamedPipeObjet.cpp \
	src/Encapsulate/CCatchLine.cpp \
	src/Encapsulate/Process.cpp

OBJ = $(SRC:.cpp=.o)

NAME  = plazza

RM = rm -f

INC_DIR = include/

CFLAGS	+= -std=c++11 -pthread -lpthread -Wl,--no-as-needed -I$(INC_DIR) -g

CC = g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -pthread -lpthread -Wl,--no-as-needed -o $(NAME) $(LDFLAGS) $(OBJ)

%.o : %.cpp
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
