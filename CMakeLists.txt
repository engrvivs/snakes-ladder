cmake_minimum_required(VERSION 3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.16)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.16)
endif()

# IMP: Set project name here
set(MY_PROJECT_NAME "snakes-ladders")

# Extract project's version
set(${MY_PROJECT_NAME}_VERSION_REGEX "#define PROJECT_VERSION[ \t]+\"(.+)\"")
# Read in the line, containing the version
file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/include/Version.hpp"
     ${MY_PROJECT_NAME}_VERSION_STRING REGEX ${${MY_PROJECT_NAME}_VERSION_REGEX})
# Pick out just the version
string(REGEX REPLACE ${${MY_PROJECT_NAME}_VERSION_REGEX} "\\1" ${MY_PROJECT_NAME}_VERSION_STRING "${${MY_PROJECT_NAME}_VERSION_STRING}")

# Set project info in the top-level CMake file
project(${MY_PROJECT_NAME} VERSION ${${MY_PROJECT_NAME}_VERSION_STRING}
                      DESCRIPTION "C++17 + Catch2 + CMake + Travis CI"
                      HOMEPAGE_URL "https://github.com/engrvivs/snakes-ladder"
                      LANGUAGES CXX)

# Print the version number of CMake, if this is the main project
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    message(STATUS "CMake ${CMAKE_VERSION}")
    
    include(CTest)
    include(FetchContent)

    # IMP: Do NOT set them for Libraries
    # Specify the required C++ standard, globally, with NO extensions (like, gnu++17)
    if(NOT DEFINED CMAKE_CXX_STANDARD)
        set(CMAKE_CXX_STANDARD 17)
    endif()

    if(NOT DEFINED CMAKE_CXX_STANDARD_REQUIRED)
        set(CMAKE_CXX_STANDARD_REQUIRED ON)
    endif()

    if(NOT DEFINED CMAKE_CXX_EXTENSIONS)
        set(CMAKE_CXX_EXTENSIONS OFF)
    endif()
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(app)

add_executable(${CMAKE_PROJECT_NAME} $<TARGET_OBJECTS:board> $<TARGET_OBJECTS:main>)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(test)
endif()
