cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-Wall -coverage")

include_directories(
    ~/github_repo/googletest/googletest/include
    ~/github_repo/googletest/googlemock/include
    ../util
)

link_directories(
    ~/github_repo/googletest/googlemock/gtest
    ~/github_repo/googletest/googlemock
    ../util
)

add_executable(UnitTest
    main.cc
)

target_link_libraries(UnitTest
    gtest
    gmock
    util
)
