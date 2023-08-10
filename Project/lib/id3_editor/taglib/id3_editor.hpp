#ifndef ID3_EDITOR_HPP_
#define ID3_EDITOR_HPP_

#include <string>
#include <cstdint>

struct SongId3 {
  std::string artist_name = "";
  std::string album_title = "";
  std::string album_cover_path = "";
  std::uint32_t album_year = 0;
  std::string album_genre = "";
  std::uint32_t track = 0;
  std::string title = "";
};

class Id3Editor {
private:
  Id3Editor();

public:
  static Id3Editor* Instance();
  void EditID3(const std::string& song_path, const SongId3& song_id3) override;
  std::uint32_t GetDuration(const std::string& song_path);
};

#endif