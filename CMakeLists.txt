cmake_minimum_required(VERSION 3.5.1)
project(efficienty_comparison_counting_chars)

set(CMAKE_CXX_STANDARD 14)

add_executable(efficienty_comparison_counting_chars words_length.cpp words_length.h time_measure.h test_one_way.cpp)