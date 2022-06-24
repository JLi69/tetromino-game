cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "-O2 -static-libstdc++ -static-libgcc")

project(c-tetris)

find_package(OpenGL REQUIRED)

add_executable(
				${PROJECT_NAME}
				${PROJECT_SOURCE_DIR}/Main.c
				${PROJECT_SOURCE_DIR}/glad.c
				${PROJECT_SOURCE_DIR}/src/DrawFrame.c
				${PROJECT_SOURCE_DIR}/src/UpdateFrame.c
				${PROJECT_SOURCE_DIR}/src/Init.c
				${PROJECT_SOURCE_DIR}/src/GeneratePiece.c
				${PROJECT_SOURCE_DIR}/src/HandleKeyInput.c
				${PROJECT_SOURCE_DIR}/src/HandleWinResize.c
)

target_link_libraries(${PROJECT_NAME} OpenGL::GL glfw3 m)
