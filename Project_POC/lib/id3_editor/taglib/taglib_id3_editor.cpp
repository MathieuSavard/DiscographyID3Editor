#include "taglib_id3_editor.hpp"

#define TAGLIB_STATIC

/*
#include <mpegfile.h>
#include <id3v2tag.h>
#include <tfilestream.h>
#include <attachedpictureframe.h>
#include <mpegproperties.h>
*/

namespace msl {

TagLibId3Editor::TagLibId3Editor() {}

TagLibId3Editor* TagLibId3Editor::Instance() {
  static TagLibId3Editor instance;
  return &instance;
}

void TagLibId3Editor::EditID3(const std::string& song_path, const SongId3& song_id3) {
  /*
    TagLib::FileName song_file_name = song_path.c_str();
  TagLib::FileName album_cover_file_name = song_id3.album_cover_path.c_str();

  TagLib::ID3v2::AttachedPictureFrame* frame = new TagLib::ID3v2::AttachedPictureFrame();
  TagLib::FileStream file_stream(album_cover_file_name, true);

  frame->setType(TagLib::ID3v2::AttachedPictureFrame::Type::FrontCover);
  frame->setMimeType("image/jpeg");
  frame->setPicture(file_stream.readBlock(file_stream.length()));

  TagLib::MPEG::File song_file(song_file_name);
  song_file.strip();
  TagLib::ID3v2::Tag *tag = song_file.ID3v2Tag(true);
  
  tag->setArtist(song_id3.artist_name);
  tag->setAlbum(song_id3.album_title);
  tag->setYear(song_id3.album_year);
  tag->setGenre(song_id3.album_genre);
  tag->setTrack(song_id3.track);
  tag->setTitle(song_id3.title);
  tag->addFrame(frame);
  
  song_file.save(TagLib::MPEG::File::TagTypes::ID3v2);
  */

}

std::uint32_t TagLibId3Editor::GetDuration(const std::string& song_path) {
  /*
    TagLib::FileName song_file_name = song_path.c_str();
  TagLib::MPEG::File song_file(song_file_name);
  TagLib::MPEG::Properties song_properties(&song_file, TagLib::AudioProperties::ReadStyle::Fast);
  return song_properties.lengthInSeconds();
  */

}

} 
