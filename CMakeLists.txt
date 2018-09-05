cmake_minimum_required(VERSION 2.8)
add_subdirectory(util)
add_executable(Test
    main.cc
)
target_link_libraries(Test util)
