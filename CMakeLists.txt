cmake_minimum_required(VERSION 3.1)

project(opencv)

find_package(OpenCV )

add_executable(main main.cpp)

link_directories(${OpenCV_LIBRARY_DIRS})
target_link_libraries(main ${OpenCV_LIBS})