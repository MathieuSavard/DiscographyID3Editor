################# HEADER #################
cmake_minimum_required(VERSION 3.20)
project(DiscographyID3Editor)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
##########################################

add_subdirectory(lib_new)
add_subdirectory(app)

add_executable(${PROJECT_NAME}
  main.cpp
  )

target_link_libraries(${PROJECT_NAME} PUBLIC app)