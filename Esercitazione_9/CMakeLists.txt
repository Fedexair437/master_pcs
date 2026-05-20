cmake_minimum_required(VERSION 3.20)

project(esercitazione9)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")


## Creo i target per gli eseguibili che effettueranno il test

enable_testing()
add_executable(test_visite_dijkstra test_visite_dijkstra.cpp)
add_test(NAME visite_dijkstra COMMAND test_visite_dijkstra)