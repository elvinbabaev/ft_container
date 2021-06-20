NAME = listExec stackExec queueExec vectorExec mapExec
SRC = Test/list_main.cpp Test/queue_main.cpp Test/stack_main.cpp Test/vector_main.cpp Test/map_main.cpp
INC = Container/list.hpp Container/queue.hpp Container/stack.hpp Container/vector.hpp \
	Element/Node.hpp Element/elem.hpp\
    iterator/Bidirectional.hpp iterator/RandomAccessIterator.hpp iterator/bidirectional_map.hpp
FLAGS = -Wall -Wextra -Werror
CC = clang++ -std=c++98

OSRC = $(SRC:.cpp=.o)

%.o: %.cpp $(HEADER)$(INC)
	$(CC) $(FLAGS) -c $< -o $@

all:list stack queue vector map

list: $(OSRC) $(INC)
	$(CC) Test/list_main.o -o listExec
	rm Test/list_main.o
stack: $(OSRC) $(INC)
	$(CC) Test/stack_main.o -o stackExec
	rm Test/stack_main.o
queue: $(OSRC) $(INC)
	$(CC) Test/queue_main.o -o queueExec
	rm Test/queue_main.o
vector: $(OSRC) $(INC)
	$(CC) Test/vector_main.o -o vectorExec
	rm Test/vector_main.o

map: $(OSRC) $(INC)
	$(CC) Test/map_main.o -o mapExec
	rm Test/map_main.o
clean:
	rm -rf $(OSRC)
fclean:clean
	rm -rf $(NAME)
re: fclean all