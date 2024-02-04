#include "file_system.hpp"

#include <filesystem>

using namespace std::filesystem;

bool FileSystem::Exist(const std::string& path) {
  return exists(path);
}

bool FileSystem::IsDirectory(const std::string& path) {
  return is_directory(path);
}

bool FileSystem::GetDirectories(const std::string& path, std::vector<std::string>& directories_out) {
  if (!exists(path) || !is_directory(path))
    return false;

  for (const directory_entry& entry : directory_iterator(path))
    if (entry.is_directory()) 
      directories_out.push_back(entry.path().string());

  return true;
}

bool FileSystem::GetDirectoryName(const std::string& path, std::string& directory_name_out) {
  std::filesystem::path directoryPath = path;

  if (is_directory(directoryPath)) {
    directory_name_out = directoryPath.filename().string();
  } else {
    return false;
  }
      
  return true;
}

bool FileSystem::IsFile(const std::string& path) {
  return is_regular_file(path);
}

//Return list of files as absolute path.
bool FileSystem::GetFiles(const std::string& path, std::vector<std::string>& files_out) {
  if (!exists(path) || !is_directory(path)) 
      return false;

  for (const directory_entry& entry : directory_iterator(path))
      if (entry.is_regular_file())
          files_out.push_back(entry.path().string());

  return true;
}

bool FileSystem::GetFileExtension(const std::string& path, std::string& file_extension_out) {
     std::filesystem::path fs_path(path);

    if (!fs_path.has_extension())
      return false;
        
    file_extension_out = fs_path.extension().string();

     if (!file_extension_out.empty()) 
        file_extension_out.erase(0, 1);

    return true;
}

bool FileSystem::GetFileName(const std::string& path, std::string& file_name_out) {
    std::filesystem::path fs_path(path);

    if (!fs_path.has_filename()) 
      return false;
    
    file_name_out = fs_path.stem().string();
    return true;
}

bool FileSystem::RenameFile(const std::string& path, const std::string& new_name) {
    std::filesystem::path fs_path(path);

    if (!exists(fs_path)) 
        return false;

    std::filesystem::path parent_path = fs_path.parent_path();
    std::filesystem::path new_path = parent_path / new_name;

    try {
        rename(fs_path, new_path);
    } catch (const std::exception& ex) {
        return false;
    }

    return true;
}