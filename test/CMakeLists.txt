# Testing library
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v2.13.1
)

# CMake 3.14+: Populate content and possibly add it to main build
# CMake target, defined by Catch2, are available to the build
FetchContent_MakeAvailable(Catch2)

set(TARGET_TEST_BOARD "test_board")
add_library(${TARGET_TEST_BOARD} OBJECT Board.cxx)
target_include_directories(${TARGET_TEST_BOARD} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${TARGET_TEST_BOARD} PRIVATE Catch2::Catch2 $<TARGET_OBJECTS:board>)

# Tests need to be added as executable
set(TARGET_TEST_MAIN "tests")
add_executable(${TARGET_TEST_MAIN} main.cxx)
target_link_libraries(${TARGET_TEST_MAIN} PRIVATE Catch2::Catch2 ${TARGET_TEST_BOARD})

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(Catch)
catch_discover_tests(${TARGET_TEST_MAIN})
