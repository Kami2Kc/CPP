cmake_minimum_required(VERSION 3.15)
project(ex2)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp ReadWords.cpp ReadWords.h ReadFilteredWords.cpp ReadFilteredWords.h filter1.cpp filter1.h filter2.cpp filter2.h filter3.cpp filter3.h)

file(GLOB SOURCES
        *.h
        *.cpp
        )

add_executable(ex2 ${SOURCE_FILES} ${SOURCES})
