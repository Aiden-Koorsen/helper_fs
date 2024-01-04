cmake_minimum_required(VERSION 3.7)

project(helper_fs_examples)

add_executable(text_files text_files.c)
add_executable(csv_files csv_files.c)

target_include_directories(text_files PRIVATE "../include")
target_link_directories(text_files PRIVATE "../build/")
target_link_libraries(text_files PRIVATE helper_fs)

target_include_directories(csv_files PRIVATE "../include")
target_link_directories(csv_files PRIVATE "../build/")
target_link_libraries(csv_files PRIVATE helper_fs)
