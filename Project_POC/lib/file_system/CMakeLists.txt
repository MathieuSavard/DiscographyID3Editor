set(FILE_SYSTEM_TARGET_NAME file_system)

set(SOURCES
  itf_file_system.cpp
)

add_library(${FILE_SYSTEM_TARGET_NAME} STATIC ${SOURCES})
target_include_directories(${FILE_SYSTEM_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})