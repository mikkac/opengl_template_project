cmake_minimum_required(VERSION 3.10)

project(template)

set(window_lib "window_lib")

set(WINDOW_SRC
	src/window.cpp
	)

set(WINDOW_INC
	inc/window.h
	)

add_subdirectory(dependencies)
include_directories(dependencies/glad/include)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW 2.0 REQUIRED)
find_package(glfw3 REQUIRED)

add_library(${window_lib} ${WINDOW_SRC} ${WINDOW_INC})
target_include_directories(${window_lib} PUBLIC inc)


add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${window_lib})
target_link_libraries(${PROJECT_NAME} "${OPENGL_LIBRARIES}"
	"${GLUT_LIBRARY}" glad glfw)

