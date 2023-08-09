#include "id3_editor.hpp"

#define TAGLIB_STATIC
#define USING_TAGLIB 1 

#if USING_TAGLIB
#include "mpegfile.h"
#include "id3v2tag.h"
#include "tfilestream.h"
#include "attachedpictureframe.h"
#include "mpegproperties.h"
#endif

Id3Editor::Id3Editor() {}

Id3Editor* Id3Editor::Instance() {
  static Id3Editor instance;
  return &instance;
}

std::uint32_t Id3Editor::GetDuration(const std::string& song_path) {
#if USING_TAGLIB
  TagLib::FileName song_file_name = song_path.c_str();
  TagLib::MPEG::File song_file(song_file_name);
  TagLib::MPEG::Properties song_properties(&song_file, TagLib::AudioProperties::ReadStyle::Fast);
  return song_properties.lengthInSeconds();
#else
  return 0;
#endif
}
