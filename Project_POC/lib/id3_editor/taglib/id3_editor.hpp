#ifndef ID3_EDITOR_HPP_
#define ID3_EDITOR_HPP_

#include <string>
#include <cstdint>

class Id3Editor {
private:
  Id3Editor();

public:
  static Id3Editor* Instance();
  std::uint32_t GetDuration(const std::string& song_path);
};

#endif