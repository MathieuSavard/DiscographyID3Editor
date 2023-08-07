#set(LIBRARY_CHOICE "TagLib" CACHE STRING "Select the library (TagLib, And, Other, or Lib)")
set(LIBRARY_CHOICE "TagLib" CACHE STRING "Select the library (TagLib)")

string(TOUPPER "${LIBRARY_CHOICE}" LIBRARY_CHOICE)

if(NOT LIBRARY_CHOICE MATCHES "TAGLIB" AND
   NOT LIBRARY_CHOICE MATCHES "AND" AND
   NOT LIBRARY_CHOICE MATCHES "OTHER" AND
   NOT LIBRARY_CHOICE MATCHES "LIB")
   #message(FATAL_ERROR "Invalid library choice. Available choices: TagLib, And, Other, or Lib")
   message(FATAL_ERROR "Invalid library choice. Available choices: TagLib")
endif()

if(LIBRARY_CHOICE STREQUAL "TAGLIB")
    add_subdirectory(taglib)
#elseif(LIBRARY_CHOICE STREQUAL "AND")
    #add_subdirectory(and)
#elseif(LIBRARY_CHOICE STREQUAL "OTHER")
    #add_subdirectory(other)
#elseif(LIBRARY_CHOICE STREQUAL "LIB")
    #add_subdirectory(lib)
endif()

set(ID3_EDITOR_TARGET_NAME id3_editor)

set(SOURCES
  itf_id3_editor.cpp
)

add_library(${ID3_EDITOR_TARGET_NAME} STATIC ${SOURCES})
target_include_directories(${ID3_EDITOR_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})