#include "file_system/boost/boost_file_system.hpp"

#include <algorithm>
#include <boost/filesystem.hpp>

namespace msl {
    
BoostFileSystem::BoostFileSystem() {}

BoostFileSystem* BoostFileSystem::Instance() {
    static BoostFileSystem instance;
    return &instance;
}

bool BoostFileSystem::Exist(const std::string& path) {
    return boost::filesystem::exists(path);
}

bool BoostFileSystem::IsDirectory(const std::string& path) {
    return boost::filesystem::is_directory(path);
}

bool BoostFileSystem::GetDirectories(const std::string& path, std::vector<std::string>& directories_out) {
    std::string directory = "";

    if(!IsDirectory(path)){
      return false;
    }

    for (boost::filesystem::directory_entry& entry : boost::filesystem::directory_iterator(path)) {
        directory = entry.path().string();

      if(IsDirectory(directory)) {
        std::replace(directory.begin(), directory.end(), '\\', '/');
        directories_out.push_back(directory);
      }
    }
  
    return true;
}

bool BoostFileSystem::GetDirectoryName(const std::string& path, std::string& directory_name_out) {
    if(!IsDirectory(path)) {
      return false;
    }

    directory_name_out = boost::filesystem::path(path).filename().string();
    
    return true;
}

bool BoostFileSystem::GetFiles(const std::string& path, std::vector<std::string>& files_out) {
    std::string file_path = "";

    if(!IsDirectory(path)){
      return false;
    }

    for (boost::filesystem::directory_entry& entry : boost::filesystem::directory_iterator(path)) {
        file_path = entry.path().string();

      if(IsFile(file_path)) {
        std::replace(file_path.begin(), file_path.end(), '\\', '/');
        files_out.push_back(file_path);
      }
    }
    
    return true;
}

bool BoostFileSystem::IsFile(const std::string& path) {
    return boost::filesystem::is_regular_file(path);
}

bool BoostFileSystem::GetFileExtension(const std::string& path, std::string& file_extension_out) {
     if(!IsFile(path)) {
       return false;
     }

     file_extension_out = boost::filesystem::path(path).extension().string();

     while(file_extension_out.find('.') != std::string::npos) {
       file_extension_out.erase(file_extension_out.find('.'), 1);
     }
     
    return true;
}

bool BoostFileSystem::GetFileName(const std::string& path, std::string& file_name_out) {
    size_t dot_position = std::string::npos;

    if(!IsFile(path)) {
      return false;
    }

    file_name_out = boost::filesystem::path(path).filename().string();

    dot_position = file_name_out.find_last_of('.');

    if(dot_position != std::string::npos) {
      file_name_out.erase(dot_position);
    }
    
    return true;
}

bool BoostFileSystem::RenameFile(const std::string& path, const std::string& new_name) {
    std::string new_file_name = path;
    std::string file_name = "";
    std::string file_extension = "";

    if(!IsFile(path)){
      return false;
    }

    if(!GetFileName(path, file_name)) {
      return false;
    }

    if(!GetFileExtension(path, file_extension)) {
      return false;
    }

    new_file_name.replace(new_file_name.find_last_of(file_extension) - file_extension.size() + 1, file_extension.size(), "");

    new_file_name.replace(new_file_name.find_last_of(file_name) - file_name.size() + 1, file_name.size(), new_name);

    new_file_name += file_extension;

    boost::filesystem::rename(path, new_file_name);
    
    return true;
}

}
