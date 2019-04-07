cmake_minimum_required(VERSION 3.10)
project(glad)

include_directories(include)

add_library(${PROJECT_NAME} SHARED "src/glad.c") 

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-w")
