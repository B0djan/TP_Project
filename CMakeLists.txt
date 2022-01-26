cmake_minimum_required(VERSION 3.21)
project(TP_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(project/include)
include_directories(project/include/include_business)

add_executable(TP_Project
        project/include/day.hpp
        project/include/duration.hpp
        project/include/event.hpp
        project/include/include_business/function.hpp
        project/include/MeetUp.hpp
        project/include/structs.hpp
        project/src/day.cpp
        project/src/duration.cpp
        project/src/event.cpp
        project/src/business/function.cpp
        project/src/MeetUp.cpp
        project/src/structs.cpp
        project/main.cpp)
