################# HEADER #################
cmake_minimum_required(VERSION 3.20)
project(CMAKE_VSCODE_MINGW)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
##########################################

project(application)

add_library(${PROJECT_NAME} STATIC
  application.cpp
  )

add_subdirectory(file_system)
add_subdirectory(id3_editor)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC file_system, id3_editor)