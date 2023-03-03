cmake_minimum_required(VERSION 3.15)
project(ex1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES ex1.cpp main.cpp Person.cpp Person.h Student.cpp Student.h)

file(GLOB SOURCES
        *.h
        *.cpp
        )

add_executable(ex1 ${SOURCE_FILES} ${SOURCES})
