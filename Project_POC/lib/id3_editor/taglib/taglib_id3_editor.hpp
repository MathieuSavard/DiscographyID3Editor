#ifndef MSL_ID3_EDITOR_TAGLIB_TAGLIB_ID3_EDITOR_HPP_
#define MSL_ID3_EDITOR_TAGLIB_TAGLIB_ID3_EDITOR_HPP_

#include "itf_id3_editor.hpp"

namespace msl {

class TagLibId3Editor : public ItfId3Editor {
private:
  TagLibId3Editor();

public:
  static TagLibId3Editor* Instance();
  void EditID3(const std::string& song_path, const SongId3& song_id3) override;
  std::uint32_t GetDuration(const std::string& song_path) override;
};

}

#endif
