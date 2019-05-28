cmake_minimum_required(VERSION 3.0)
project(TripMate)

set(CMAKE_CXX_STANDARD 17)

find_package (Threads)

add_executable(TripMate TestGraph.cpp Graph.h GraphViewer/graphviewer.cpp GraphViewer/graphviewer.h MutablePriorityQueue.h Coordinates.cpp Coordinates.h Heuristics.h Heuristics.cpp GraphViewer/GraphicalInterface.cpp GraphViewer/GraphicalInterface.h Graph.cpp Appointment.h Appointment.cpp
            Coordinates.h Coordinates.cpp TestGraph.h Schedule.h Schedule.cpp Utils.h Utils.cpp UImain.cpp TripMate.cpp TripMate.h GraphViewer/connection.h GraphViewer/connection.cpp)

target_link_libraries (TripMate ${CMAKE_THREAD_LIBS_INIT})
