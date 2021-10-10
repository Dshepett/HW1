# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(HW1 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
    # Headers
    rnd.h
    parallelepiped.h
    sphere.h
    tetrahedron.h
    shape.h
    container.h

    # Sources
    container.cpp
    main.cpp
    parallelepiped.cpp
    shape.cpp
    sphere.cpp
    tetrahedron.cpp
)

add_executable(HW1 ${SOURCE_FILES})
