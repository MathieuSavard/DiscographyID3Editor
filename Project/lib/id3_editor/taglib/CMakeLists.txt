set(ID3_EDITOR_TARGET_NAME id3_editor)

set(SOURCES
  id3_editor.cpp
)

add_library(${ID3_EDITOR_TARGET_NAME} STATIC ${SOURCES})

target_include_directories(${ID3_EDITOR_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(${ID3_EDITOR_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/taglib/build/install/include/taglib/)
target_link_libraries(${ID3_EDITOR_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/taglib/build/install/lib/libtag.a)