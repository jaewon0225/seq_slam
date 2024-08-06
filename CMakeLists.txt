cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src
                    include
)

add_library(seqslam 
            src/preprocessor.cpp
            src/sequence_matcher.cpp
)

target_include_directories(seqslam
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_INSTALL_INCLUDEDIR}
)

set(PUBLIC_HEADERS
    preprocessor.h
    sequence_matcher.h
)

set_target_properties(seqslam PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADERS}")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(seqslam
    PUBLIC
    ${OpenCV_LIBS}
)

install(TARGETS seqslam DESTINATION lib
        PUBLIC_HEADER DESTINATION include
)

# -----------------------------
# Example usage
add_subdirectory( example )