# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.10)

# Project's name

project(mylocraft)
# Set the output folder where your program will be created
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(SOURCES ${PROJECT_SOURCE_DIR}/src/core/database.cpp
            ${PROJECT_SOURCE_DIR}/src/ui/mainwindow.cpp
            ${PROJECT_SOURCE_DIR}/src/main.cpp)
set(HEADERS ${PROJECT_SOURCE_DIR}/src/core/database.hpp
            ${PROJECT_SOURCE_DIR}/src/ui/mainwindow.hpp)

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

find_package(Qt5 COMPONENTS Widgets Sql REQUIRED)

add_executable(mylocraft ${HEADERS} ${SOURCES})

target_link_libraries(mylocraft Qt5::Widgets Qt5::Sql)
