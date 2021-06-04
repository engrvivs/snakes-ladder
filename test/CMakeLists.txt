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
target_link_libraries(${TARGET_TEST_BOARD} PRIVATE Catch2::Catch2)

# Tests need to be added as executable
set(TARGET_TEST_MAIN "test_main")
add_library(${TARGET_TEST_MAIN} OBJECT main.cxx)
target_link_libraries(${TARGET_TEST_MAIN} PRIVATE Catch2::Catch2)

set(TARGET_TEST "tests")
add_executable(${TARGET_TEST})
if(ENABLE_COVERAGE)
    target_compile_options(${TARGET_TEST} BEFORE PRIVATE --coverage)
    target_link_libraries(${TARGET_TEST} PRIVATE --coverage)
endif()
target_link_libraries(${TARGET_TEST} PRIVATE ${TARGET_TEST_MAIN} ${TARGET_TEST_BOARD} $<TARGET_OBJECTS:board>)

# Add Catch2 to CMake module path
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(Catch)
catch_discover_tests(${TARGET_TEST})
