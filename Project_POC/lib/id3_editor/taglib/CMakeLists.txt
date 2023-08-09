#################### Install TagLib ####################

########################################################


#################### TagLib ####################
#set(TAGLIB_TARGET_NAME tag)
#add_library()
#target_include_directories(${TAGLIB_TARGET_NAME} PUBLIC "C:/Libraries/taglib/include/taglib")
########################################################



########################################################
#find_package(TagLib REQUIRED)


set(ID3_EDITOR_TARGET_NAME id3_editor)
set(SOURCES
  id3_editor.cpp
)
add_library(${ID3_EDITOR_TARGET_NAME} STATIC ${SOURCES})
target_include_directories(${ID3_EDITOR_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${ID3_EDITOR_TARGET_NAME} PUBLIC "C:/Libraries/taglib/include/taglib")
target_link_libraries(${ID3_EDITOR_TARGET_NAME} PUBLIC "C:/Libraries/taglib/lib/libtag.a")

#target_link_libraries(${ID3_EDITOR_TARGET_NAME} PUBLIC ${TAGLIB_TARGET_NAME})

########################################################


#target_link_libraries(${TAGLIB_TARGET_NAME} PRIVATE TagLib::TagLib)

