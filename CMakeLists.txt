cmake_minimum_required(VERSION 3.5.2)
project(efficienty_comparison_counting_chars)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)

add_executable(test_one_way words_length.cpp test_one_way.cpp)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
target_link_libraries(test_one_way)
