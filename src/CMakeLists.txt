set(TARGET_BOARD "board")
add_library(${TARGET_BOARD} OBJECT Board.cxx)
target_include_directories(${TARGET_BOARD} PRIVATE ${PROJECT_SOURCE_DIR}/include)
