project(algoritmi_array)
project(indirizzi)
project(testo_es) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(algoritmi_array algoritmi_array.cpp)
add_executable(indirizzi indirizzi.cpp)
add_executable(testo_es testo_es.cpp)