cmake_minimum_required(VERSION 3.20.0)
project(comm)

include_directories(${CMAKE_SOURCE_DIR}/inc)

FILE(GLOB srcs src/*.c)
add_library(comm STATIC ${srcs})

# Install rules (optional)
install(TARGETS comm
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY inc/ DESTINATION inc)
