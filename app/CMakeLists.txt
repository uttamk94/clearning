cmake_minimum_required(VERSION 3.20.0)
project(app)

include_directories(${CMAKE_SOURCE_DIR}/inc)
include_directories(${CMAKE_SOURCE_DIR}/parser/inc)
include_directories(${CMAKE_SOURCE_DIR}/sync_mgr/inc)
include_directories(${CMAKE_SOURCE_DIR}/twcc/inc)

add_subdirectory(parser)
add_subdirectory(sync_mgr)
add_subdirectory(twcc)

add_executable(app
    src/main.c
)

target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/parser/inc)
target_link_libraries(app PRIVATE parser)

target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/sync_mgr/inc)
target_link_libraries(app PRIVATE sync_mgr)

target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/twcc/inc)
target_link_libraries(app PRIVATE twcc)

# Include directory (for headers like mylib.h)
target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/inc)

# Link the .lib file
target_link_libraries(app PRIVATE ${CMAKE_SOURCE_DIR}/lib/comm.lib)