cmake_minimum_required(VERSION 3.20)
project(LeetCode_CodeWars_Solutions)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB TASKS "*.cpp")

foreach(TASK_FILE ${TASKS})
    get_filename_component(TASK_NAME ${TASK_FILE} NAME_WE)
    string(STRIP ${TASK_NAME} TASK_NAME)
    string(REGEX REPLACE "[^a-zA-Z0-9_]" "_" TASK_NAME "${TASK_NAME}")

    add_executable(${TASK_NAME} ${TASK_FILE})

    if(MSVC)
        target_compile_options(${TASK_NAME} PRIVATE /W4 /permissive-)
    else()
        target_compile_options(${TASK_NAME} PRIVATE -Wall -Wextra -Wpedantic -O2)
    endif()
endforeach()
