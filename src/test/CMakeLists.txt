cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-Wall -coverage")

include_directories(
    ~/googletest/googletest/include
    ~/googletest/googlemock/include
    #../util
)

link_directories(
  #~/github_repo/googletest/googlemock/gtest
  #~/github_repo/googletest/googlemock
    ~/googletest/build/lib
)

 # 直接のサブディレクトリでないディレクトリに依存する場合の定義法
 #   => stackoverflow 7980784
 #add_subdirectory(../util ../../util)
 add_subdirectory(util) # symlink

# For creating LCOV HTML
#   $ cmake ..
#   $ make
#   $ make coverage
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    APPEND_COVERAGE_COMPILER_FLAGS(coverage)
    SETUP_TARGET_FOR_COVERAGE_LCOV(
        NAME coverage
        EXECUTABLE ./UnitTest.exe # .exe for cygwin
        DEPENDENCIES util)
endif()


add_executable(UnitTest
    main.cc
)

target_link_libraries(UnitTest
    util
    gtest
    gmock
    pthread
)
