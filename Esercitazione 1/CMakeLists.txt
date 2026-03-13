# In un file CMakeLists.txt si deve innanzitutto specificare la versione
# minima di CMake necessaria per compilare il progetto. Nel nostro caso
cmake_minimum_required(VERSION 3.20)

project(stampa_arg)
project(media_temperature) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

add_executable(stampa_arg stampa_arg.cpp)
add_executable(media_temperature media_temperature.cpp)

