cmake_minimum_required(VERSION 3.20)
project(go01)

set(CMAKE_CXX_STANDARD 14)

add_executable(go01 main.cpp 2.1.cpp 2.3.cpp 2.8.cpp 1.8.cpp 1.9.cpp 2.4.cpp 2.5.cpp 2.6.cpp 2.7.cpp)

add_executable(1.1 1.1.cpp)
add_executable(2.2 2.2.cpp)
add_executable(2.1 2.1.cpp)
add_executable(2.3 2.3.cpp)
add_executable(2.8 2.8.cpp)
add_executable(1.8 1.8.cpp)


add_executable(2.4 2.4.cpp)
add_executable(2.7 2.7.cpp)
add_executable(2.6 2.6.cpp)
add_executable(2.5 2.5.cpp)