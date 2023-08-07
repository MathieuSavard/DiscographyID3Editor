#ifndef MSL_FILE_SYSTEM_ITF_FILE_SYSTEM_HPP_
#define MSL_FILE_SYSTEM_ITF_FILE_SYSTEM_HPP_

#include <string>
#include <vector>

namespace msl {

class ItfFileSystem {
public:
  virtual ~ItfFileSystem();

  virtual bool Exist(const std::string& path) = 0;

  virtual bool IsDirectory(const std::string& path) = 0;

  virtual bool GetDirectories(const std::string& path, std::vector<std::string>& directories_out) = 0;

  virtual bool GetDirectoryName(const std::string& path, std::string& directory_name_out) = 0;

  virtual bool IsFile(const std::string& path) = 0;

  //Return list of files as absolute path.
  virtual bool GetFiles(const std::string& path, std::vector<std::string>& files_out) = 0;

  virtual bool GetFileExtension(const std::string& path, std::string& file_extension_out) = 0;

  virtual bool GetFileName(const std::string& path, std::string& file_name_out) = 0;

  virtual bool RenameFile(const std::string& path, const std::string& new_name) = 0;
};

}

#endif
