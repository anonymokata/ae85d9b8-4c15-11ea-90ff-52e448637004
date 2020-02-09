project(Google_tests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(test_pencil_durability test_pencil_durability.cpp test_paper.cpp test_eraser.cpp test_pencil_point.cpp)
target_link_libraries(test_pencil_durability gtest gtest_main PencilDurabilityKata)
add_test(test_pencil_durability test_pencil_durability)

