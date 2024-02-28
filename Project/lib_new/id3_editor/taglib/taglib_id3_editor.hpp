#ifndef TAGLIB_ID3_EDITOR_HPP_
#define TAGLIB_ID3_EDITOR_HPP_

#include "itf_id3_editor.hpp"

class TagLibId3Editor : public ItfId3Editor {
private:
  TagLibId3Editor();

public:
  static TagLibId3Editor* Instance();
  void EditID3(const std::string& song_path, const SongId3& song_id3) override;
  std::uint32_t GetDuration(const std::string& song_path) override;
};

#endif