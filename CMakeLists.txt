cmake_minimum_required(VERSION 3.0.0)
project(Snake VERSION 0.1.0)

include(CTest)
enable_testing()

link_directories("C:/SFML/SFML-2.5.1/lib")

add_executable( ${PROJECT_NAME} SourceFiles/MainWin.cpp SourceFiles/board.cpp SourceFiles/initializer.cpp SourceFiles/object.cpp SourceFiles/snake.cpp SourceFiles/windows.cpp) 

target_include_directories( ${PROJECT_NAME} PUBLIC "C:/SFML/SFML-2.5.1/include")
target_link_libraries( ${PROJECT_NAME} opengl32 winmm gdi32 sfml-system sfml-window sfml-graphics)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
