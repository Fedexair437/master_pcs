cmake_minimum_required(VERSION 3.20)

project(esercitazione11)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(test_cicli_fondamentali test_cicli_fondamentali.cpp)

add_executable(test_cicli_fondamentali_2 test_cicli_fondamentali_2.cpp)