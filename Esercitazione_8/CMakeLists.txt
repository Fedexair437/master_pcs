cmake_minimum_required(VERSION 3.20)

project(esercitazione8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")


## Creo i target per gli eseguibili che effettueranno i test unitari

add_executable(test_undirected_edge test_undirected_edge.cpp)
add_test(NAME undirected_edge COMMAND test_undirected_edge)

add_executable(test_undirected_graph test_undirected_graph.cpp)
add_test(NAME undirected_graph COMMAND test_undirected_graph)

enable_testing()