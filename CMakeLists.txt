cmake_minimum_required(VERSION 3.21)
project(TP_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(project/include)
include_directories(project/include/include_business)

add_executable(TP_Project
        project/include/include_business/day.hpp
        project/include/include_business/duration.hpp
        project/include/include_business/event.hpp
        project/include/include_business/function.hpp
        project/include/include_business/MeetUp.hpp
        project/include/include_business/structs.hpp
        project/src/business/day.cpp
        project/src/business/duration.cpp
        project/src/business/event.cpp
        project/src/business/function.cpp
        project/src/business/MeetUp.cpp
        project/src/business/structs.cpp
        project/main.cpp)
