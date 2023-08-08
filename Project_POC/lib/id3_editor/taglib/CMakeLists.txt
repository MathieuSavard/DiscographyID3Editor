add_subdirectory(taglib)

set(TAGLIB_TARGET_NAME my_taglib)

set(SOURCES
  taglib_id3_editor.cpp
)

add_library(${TAGLIB_TARGET_NAME} STATIC ${SOURCES})
target_link_libraries(${TAGLIB_TARGET_NAME} PUBLIC tag)
target_include_directories(${TAGLIB_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(${TAGLIB_TARGET_NAME} PRIVATE taglib_id3_editor.hpp)