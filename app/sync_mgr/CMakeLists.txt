include_directories(${CMAKE_SOURCE_DIR}/inc)
FILE(GLOB src_files src/*.c)
add_library(sync_mgr ${src_files})