#ifndef FILE_SYSTEM_H_
#define FILE_SYSTEM_H_

#include <string>
#include <vector>
#include <filesystem>

class FileSystem {
public:
  static bool Exist(const std::string& path);

  static bool IsDirectory(const std::string& path);

  static bool GetDirectories(const std::string& path, std::vector<std::string>& directories_out);

  static bool GetDirectoryName(const std::string& path, std::string& directory_name_out);

  static bool IsFile(const std::string& path);

  //Return list of files as absolute path.
  static bool GetFiles(const std::string& path, std::vector<std::string>& files_out);

  static bool GetFileExtension(const std::string& path, std::string& file_extension_out);

  static bool GetFileName(const std::string& path, std::string& file_name_out);

  static bool RenameFile(const std::string& path, const std::string& new_name);
};

#endif