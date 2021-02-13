NAME = listExec stackExec queueExec vectorExec
SRC = Test/main.cpp Test/queue.cpp Test/stack_main.cpp Test/vector_main.cpp
INC = Container/list.hpp Container/queue.hpp Container/stack.hpp Container/vector.hpp \
	Element/Node.hpp\
    Iterator/Bidirectional.hpp Iterator/RandomAccessIterator.hpp\
#FLAGS = -Wall -Wextra -Werror
CC = clang++
#OBJ = obj/main.cpp obj/queue.cpp obj/stack_main.cpp obj/vector_main.cpp

OSRC = $(SRC:.cpp=.o)

%.o: %.cpp $(HEADER)$(INC)
	$(CC) $(FLAGS) -c $< -o $@

all:list stack queue vector

list: $(OSRC) $(INC)
	$(CC) Test/main.o -o listExec
	rm Test/main.o
stack: $(OSRC) $(INC)
	$(CC) Test/stack_main.o -o stackExec
	rm Test/stack_main.o
queue: $(OSRC) $(INC)
	$(CC) Test/queue.o -o queueExec
	rm Test/queue.o
vector: $(OSRC) $(INC)
	$(CC) Test/vector_main.o -o vectorExec
	rm Test/vector_main.o

clean:
	rm -rf $(OSRC)
fclean:clean
	rm -rf $(NAME)
re: fclean all
#all: $(NAME)
#
#$(NAME):$(OSRC) $(INC)
#	gcc $(OSRC) -o $(NAME)
#
#list:
#
#

#
#clean:
#	rm -rf $(OSRC)
#
#fclean:clean
#	rm -rf $(NAME)
#
#re: fclean all