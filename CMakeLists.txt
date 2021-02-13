cmake_minimum_required(VERSION 3.17)
project(ft_container)

set(CMAKE_CXX_STANDARD 14)

include_directories(Container)
include_directories(Element)
include_directories(iterator)

add_executable(ft_container Test/vector_main.cpp
        Container/list.hpp
        Container/queue.hpp
        Container/stack.hpp
        Container/vector.hpp
        Element/Node.hpp
        iterator/Bidirectional.hpp
        iterator/RandomAccessIterator.hpp)
#        Test/main.cpp
#        Test/queue.cpp
#        Test/stack_main.cpp
#        Test/vector_main.cpp)
