cmake_minimum_required(VERSION 3.20.0)
project(app)

include_directories(${CMAKE_SOURCE_DIR}/inc)
include_directories(${CMAKE_SOURCE_DIR}/parser/inc)

add_subdirectory(parser)

add_executable(app
    src/main.c
)

target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/parser/inc)
target_link_libraries(app PRIVATE parser)

# Include directory (for headers like mylib.h)
target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/inc)

# Link the .lib file
target_link_libraries(app PRIVATE ${CMAKE_SOURCE_DIR}/lib/comm.lib)