################# HEADER #################
cmake_minimum_required(VERSION 3.20)
project(DiscographyID3Editor)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
##########################################

set(SOURCES
  application/main.cpp
  application/application.cpp
  file_system/itf_file_system.cpp
  file_system/boost/boost_file_system.cpp
  id3_editor/itf_id3_editor.cpp
  id3_editor/taglib/taglib_id3_editor.cpp
)

set(HEADERS
  application/application.hpp
  file_system/itf_file_system.hpp
  file_system/boost/boost_file_system.hpp
  id3_editor/itf_id3_editor.hpp
  id3_editor/taglib/taglib_id3_editor.hpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
  ${PROJECT_SOURCE_DIR}/application
  ${PROJECT_SOURCE_DIR}/file_system
  ${PROJECT_SOURCE_DIR}/file_system/boost
  ${PROJECT_SOURCE_DIR}/id3_editor
  ${PROJECT_SOURCE_DIR}/id3_editor/taglib
  ${PROJECT_SOURCE_DIR}
)

################# MSVC CONFIGURATION #################
# If on Windows, and if MSVC is installed
cmake_policy(SET CMP0091 NEW)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
##################################

################# BOOST LIBRARY #################
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)

set(BOOST_ROOT C:/Libraries/boost_1_78_0)

find_package(Boost)

if(Boost_FOUND)
  target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIR})
  target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE ${Boost_LIBRARY_DIRS})  
else()
  message("Boost not found")
endif()

target_link_libraries(${CMAKE_PROJECT_NAME} ${Boost_LIBRARIES})
##################################

################# TAGLIB LIBRARY #################
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE C:/Libraries/taglib/include/taglib)
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE C:/Libraries/taglib/lib)  

target_link_libraries(${CMAKE_PROJECT_NAME} tag)
##################################