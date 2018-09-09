cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-Wall -coverage")

add_subdirectory(util)

add_executable(Test
    main.cc
)

target_link_libraries(Test util)

install(TARGETS Test DESTINATION ~/bin)
