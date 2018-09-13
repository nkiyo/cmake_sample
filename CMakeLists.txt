cmake_minimum_required(VERSION 2.8)

project(CMakeSample)

set(CMAKE_CXX_FLAGS "-Wall -coverage")
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

# For creating LCOV HTML
#   $ cmake ..
#   $ make
#   $ make coverage
if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    APPEND_COVERAGE_COMPILER_FLAGS(coverage)
    SETUP_TARGET_FOR_COVERAGE_LCOV(
        NAME coverage
        EXECUTABLE ./${PROJECT_NAME}.exe # .exe for cygwin
        DEPENDENCIES util)
endif()

add_subdirectory(util)

add_executable(${PROJECT_NAME}
    main.cc
)

target_link_libraries(${PROJECT_NAME} util)

# for make install
install(TARGETS ${PROJECT_NAME} DESTINATION ~/bin)
