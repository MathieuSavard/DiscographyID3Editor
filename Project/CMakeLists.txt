################# HEADER #################
cmake_minimum_required(VERSION 3.20)
project(DiscographyID3Editor)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
##########################################

add_subdirectory(lib)

add_executable(${PROJECT_NAME}
  main.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC printer)