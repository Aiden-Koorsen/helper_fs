cmake_minimum_required(VERSION 3.7)

project(helper_fs)

file(GLOB_RECURSE SOURCE_CODE src/*.c)

add_library(${PROJECT_NAME} STATIC ${SOURCE_CODE})

target_include_directories(${PROJECT_NAME} PRIVATE include)
# target_link_libraries(${PROJECT_NAME} PRIVATE)
