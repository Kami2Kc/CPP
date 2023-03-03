cmake_minimum_required(VERSION 3.15)
project(C___Project)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES ex2.cpp ReadWords.cpp ReadWordsBar.cpp ReadWordsBar.h ReadWords.h)

file(GLOB SOURCES
        *.h
        *.cpp
        )

add_executable(C___Project ${SOURCE_FILES} ${SOURCES})

