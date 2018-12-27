cmake_minimum_required (VERSION 3.1)

set (CMAKE_CXX_STANDARD 17)

file (GLOB MY_SRCS *.cxx)
file (GLOB MY_HDRS *.hxx)

add_executable (routing ${MY_SRCS} ${MY_HDRS})
