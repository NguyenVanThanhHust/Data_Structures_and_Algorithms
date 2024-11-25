cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(bst LANGUAGES CXX CUDA)

option(CUDA_USE_STATIC_CUDA_RUNTIME OFF)

set(CMAKE_BUILD_TYPE "Release")
set(OpenGL_GL_PREFERENCE  GLVND)
add_definitions("-DENABLE_SSE")

set(CMAKE_CXX_FLAGS "-std=c++17 -O3 -pthread -Wall -Ofast -Wfatal-errors -D_MWAITXINTRIN_H_INCLUDED")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

FIND_PACKAGE(Boost COMPONENTS program_options REQUIRED)

message(STATUS "Gstreamer source: ${GSTREAMER_INCLUDE_DIR}")
include_directories(
    /usr/include/glib-2.0
    /usr/local/cuda/include
    src
    )

link_directories(/usr/local/cuda/lib64)

set(MAIN_SRC src)
add_executable(${PROJECT_NAME}
    main.cpp
    BinarySearchTree.h
    BinarySearchTree.cpp
    )


target_link_libraries(${PROJECT_NAME}
    PRIVATE
    cudart
    cuda
)

SET(THREADS_PREFER_PTHREAD_FLAG ON)
FIND_PACKAGE(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)