#ifndef MSL_ID3_EDITOR_ITF_ID3_EDITOR_HPP_
#define MSL_ID3_EDITOR_ITF_ID3_EDITOR_HPP_

#include <string>
#include <cstdint>

namespace msl {

struct SongId3 {
  std::string artist_name = "";
  std::string album_title = "";
  std::string album_cover_path = "";
  std::uint32_t album_year = 0;
  std::string album_genre = "";
  std::uint32_t track = 0;
  std::string title = "";
};

class ItfId3Editor {
 public:
  virtual ~ItfId3Editor();
  virtual void EditID3(const std::string& song_path, const SongId3& song_id3) = 0;
  virtual std::uint32_t GetDuration(const std::string& song_path) = 0;
};

}  // namespace DiscographyId3Editor

#endif
