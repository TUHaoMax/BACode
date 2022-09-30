cmake_minimum_required(VERSION 3.20)
project(OnLineopening)

set(CMAKE_CXX_STANDARD 14)

include_directories(C:/Users/htu/AppData/Local/Programs/Python/Python310/include)
link_libraries(C:/Users/htu/AppData/Local/Programs/Python/Python310/libs/python310.lib)

add_executable(OnLineopening main.cpp OP.cpp OP.h )