################# HEADER #################
cmake_minimum_required(VERSION 3.20)
project(DiscographyID3Editor)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
##########################################

add_library(application STATIC
  application.cpp
  )

add_subdirectory(file_system)
add_subdirectory(id3_editor)

target_include_directories(application PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(application PUBLIC file_system id3_editor)

add_executable(${PROJECT_NAME}
  main.cpp
  )

target_link_libraries(${PROJECT_NAME} PUBLIC application)