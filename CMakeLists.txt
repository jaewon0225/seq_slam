cmake_minimum_required(VERSION 3.20)
project(seq_slam)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src
                    include)
set(SOURCES src/seq_slam.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})