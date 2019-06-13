cmake_minimum_required(VERSION 3.13)
project(SO2_P3)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread -lncurses")
find_package(Threads)
find_package(Curses)
set(ADDITIONAL_LIBRARIES menu)

add_executable(SO2_P3 main.cpp Objects/Car.cpp Objects/Car.h Objects/Passenger.cpp Objects/Passenger.h Objects/Airplane.cpp Objects/Airplane.h Objects/Guard.cpp Objects/Guard.h Objects/Gate.cpp Objects/Gate.h Sync.h Visualisation.cpp Visualisation.h Simulation.cpp Simulation.h Objects/Base/Thread.cpp Objects/Base/Thread.h Objects/Base/Resource.cpp Objects/Base/Resource.h Objects.h)
target_link_libraries(SO2_P3 Threads::Threads curses menu)