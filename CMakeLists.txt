cmake_minimum_required(VERSION 3.28.1)

project(rollingsum VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(rollingsum.h.in rollingsum.h)

add_library(${PROJECT_NAME} src/rollingsum.cpp)

target_sources(${PROJECT_NAME} PRIVATE src/rollingsum.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}"
)

add_subdirectory(test)

