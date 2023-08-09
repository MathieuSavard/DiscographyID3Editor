set(ID3_EDITOR_TARGET_NAME id3_editor)

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
    set(SUBDIRECTORY "taglib")
#elseif(LIBRARY_CHOICE STREQUAL "AND")
    #set(SUBDIRECTORY "taglib")
#elseif(LIBRARY_CHOICE STREQUAL "OTHER")
    #set(SUBDIRECTORY "taglib")
#elseif(LIBRARY_CHOICE STREQUAL "LIB")
    #set(SUBDIRECTORY "taglib")
endif()

add_subdirectory(${SUBDIRECTORY})
target_link_libraries(${ID3_EDITOR_TARGET_NAME} PUBLIC ${SUBDIRECTORY_TARGET})
