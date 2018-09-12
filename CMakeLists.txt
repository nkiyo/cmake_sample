cmake_minimum_required(VERSION 2.8)

project(CMakeSample)

set(CMAKE_CXX_FLAGS "-Wall -coverage")
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

#if(CMAKE_COMPILER_IS_GNUCXX)
#    include(CodeCoverage)
#    #setup_target_for_coverage(test_coverage testtest coverage)
#    APPEND_COVERAGE_COMPILER_FLAGS(coverage)
#    SETUP_TARGET_FOR_COVERAGE_LCOV(${PROJECT_NAME}_coverage Test util)
#endif()
#
#if(CMAKE_COMPILER_IS_GNUCXX)
#    #    target_link_libraries(Test gcov)
#endif()

add_subdirectory(util)

add_executable(${PROJECT_NAME}
    main.cc
)

target_link_libraries(${PROJECT_NAME} util)

install(TARGETS ${PROJECT_NAME} DESTINATION ~/bin)
