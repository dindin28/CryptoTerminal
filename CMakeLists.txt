cmake_minimum_required(VERSION 3.10)

file(TO_CMAKE_PATH "${CMAKE_CURRENT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
  message(FATAL_ERROR "You cannot build in a source directory. Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

project(EmpireBuchaBot
        VERSION 1.0
        DESCRIPTION "Bot to communicate with students"
        LANGUAGES CXX)

option(ANALYZE "Turn on static analyzer" ON)

include("${PROJECT_SOURCE_DIR}/cmake/astyle.cmake")

add_subdirectory(lib)
add_subdirectory(src)

#Include static analyzer target (cppcheck)
include("${PROJECT_SOURCE_DIR}/cmake/cppcheck.cmake")