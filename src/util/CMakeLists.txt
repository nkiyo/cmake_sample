cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-Wall -coverage")

add_library(util STATIC
    MyClass.cc
)

