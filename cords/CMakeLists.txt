cmake_minimum_required (VERSION 2.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project (cords)
file(GLOB SRC src/*.cpp)
add_executable(cords ${SRC})

