#ifndef MSL_FILE_SYSTEM_BOOST_BOOST_FILE_SYSTEM_HPP_
#define MSL_FILE_SYSTEM_BOOST_BOOST_FILE_SYSTEM_HPP_

#include "file_system/itf_file_system.hpp"

namespace msl {

class BoostFileSystem : public ItfFileSystem {
 private:
  BoostFileSystem();

 public:
  static BoostFileSystem* Instance();

  bool Exist(const std::string& path) override;

  bool IsDirectory(const std::string& path) override;

  bool GetDirectories(const std::string& path,
                      std::vector<std::string>& directories_out) override;

  bool GetDirectoryName(const std::string& path,
                        std::string& directory_name_out) override;

  bool IsFile(const std::string& path) override;

  bool GetFiles(const std::string& path,
                std::vector<std::string>& files_out) override;

  bool GetFileExtension(const std::string& path,
                        std::string& file_extension_out) override;

  bool GetFileName(const std::string& path,
                   std::string& file_name_out) override;

  bool RenameFile(const std::string& path,
                  const std::string& new_name) override;
};

}  // namespace DiscographyId3Editor

#endif
