cmake_minimum_required(VERSION 3.11)

if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
	message("on windows\n")
	set(CMAKE_C_FLAGS "-O2 -static-libgcc -mwindows -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,-Bdynamic,--no-whole-archive")	
else()
	message("on linux\n")	
	set(CMAKE_C_FLAGS "-O2 -static-libgcc")
endif()

project(c-tetris)

find_package(OpenGL REQUIRED)

include_directories(glad/include)

add_executable(
	${PROJECT_NAME}
	
	${PROJECT_SOURCE_DIR}/Main.c
	${PROJECT_SOURCE_DIR}/glad/src/glad.c
	${PROJECT_SOURCE_DIR}/src/DrawFrame.c
	${PROJECT_SOURCE_DIR}/src/UpdateFrame.c
	${PROJECT_SOURCE_DIR}/src/Init.c
	${PROJECT_SOURCE_DIR}/src/GeneratePiece.c
	${PROJECT_SOURCE_DIR}/src/HandleKeyInput.c
	${PROJECT_SOURCE_DIR}/src/HandleWinResize.c
)

target_link_libraries(${PROJECT_NAME} OpenGL::GL) 
target_link_libraries(${PROJECT_NAME} glfw3)
target_link_libraries(${PROJECT_NAME} m)
