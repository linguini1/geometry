cmake_minimum_required(VERSION 3.23)
project(geometry C)

set(CMAKE_C_STANDARD 99)

set(SDL2_INCLUDE_DIR C:\\MinGW\\include\\SDL2\\include)
set(SDL2_LIB_DIR C:\\MinGW\\include\\SDL2\\lib\\x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(geometry main.c)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
