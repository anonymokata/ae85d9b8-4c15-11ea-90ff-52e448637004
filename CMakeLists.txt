cmake_minimum_required(VERSION 3.14)
project(PencilDurabilityKata)

set(CMAKE_CXX_STANDARD 14)
enable_testing()

add_library(PencilDurabilityKata library.cpp library.h)

add_subdirectory(unittests)