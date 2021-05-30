# Testing library
set(TARGET_TEST_MAIN "test_main")
set(TARGET_TEST_BOARD "test_board")

# Tests need to be added as executables first
add_library(${TARGET_TEST_MAIN} OBJECT main.cxx)
target_include_directories(${TARGET_TEST_MAIN} PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_library(${TARGET_TEST_BOARD} OBJECT Board.cxx)
target_include_directories(${TARGET_TEST_BOARD} PRIVATE ${PROJECT_SOURCE_DIR}/include)
