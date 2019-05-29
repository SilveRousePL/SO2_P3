cmake_minimum_required(VERSION 3.13)
project(SO2_P3)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread -lncurses")
find_package(Threads)
find_package(Curses)
set(ADDITIONAL_LIBRARIES menu)

add_executable(SO2_P3 main.cpp)
target_link_libraries(SO2_P3 Threads::Threads curses menu)