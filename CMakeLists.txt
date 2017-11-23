cmake_minimum_required(VERSION 3.7)
project(OK)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        instance.cpp
        instance.h
        main.cpp)

add_executable(OK ${SOURCE_FILES})