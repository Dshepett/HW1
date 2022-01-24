# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(HW5 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")
SET(CMAKE_CXX_FLAGS -pthread)

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
        # Headers
        map.h
        captainSilver.h
        groupOfPirates.h

        # Sources
        main.cpp
        map.cpp
        groupOfPirates.cpp
        captainSilver.cpp

        )

add_executable(HW5 ${SOURCE_FILES})
