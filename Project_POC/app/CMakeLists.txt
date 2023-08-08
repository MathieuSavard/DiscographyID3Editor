set(APP_TARGET_NAME app)

set(SOURCES
  app.cpp
)

add_library(${APP_TARGET_NAME} STATIC ${SOURCES})
target_link_libraries(${APP_TARGET_NAME} PUBLIC id3_editor file_system)
target_include_directories(${APP_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
