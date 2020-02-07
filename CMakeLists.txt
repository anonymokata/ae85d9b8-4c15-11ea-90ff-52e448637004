cmake_minimum_required(VERSION 3.14)
project(PencilDurabilityKata)

set(CMAKE_CXX_STANDARD 17)
enable_testing()

add_library(PencilDurabilityKata Pencil.cpp Pencil.h Paper.cpp Paper.h)
target_compile_options(PencilDurabilityKata PRIVATE -Wall -Wextra -Werror)


add_subdirectory(unittests)