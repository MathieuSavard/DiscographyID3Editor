#ifndef APP_HPP_
#define APP_HPP_

#include <string>
#include <vector>

#include "id3_editor.hpp"
#include "file_system.hpp"

using namespace std;

const string track_title_duration_separator = "=";
const string duration_separator = ":";
const string information_file_extension = "txt";
const string album_cover_file_extension = "jpg";
const string song_file_extension = "mp3";
const string path_slash_separator = "\\";

class Application {
public:
  Application();
  int Start();

 private:
   Id3Editor* id3_editor = nullptr;

   bool edit_id3 = false;
   bool display_errors = true;
   string artist_absolute_path = "";

   bool is_valid = true;
   string artist_name = "";
   vector<string> album_absolute_paths = {};
   vector<SongId3> song_id3s = {};

   string album_absolute_path = "";
   vector<string> album_information_file_content = {};
   vector<string> song_files = {};
   vector<string> unnecessary_files = {};

   void EditId3s();
   void PrintUnnecessaryDirectory(SongId3& track_id3);
   void PrintUnnecessaryFiles();
   bool ValidateDuration(const string& entry, const SongId3& song_id3, const string& duration_string);
   bool RemoveExistingSong(const SongId3& track_id3);
   void ValidateTitle(const string& title);
   void ValidateTrack(const string& track_name);
   bool GetEntryFields(const string& entry, string& track_name, string& title_name, string& duration_string);
   void ValidateSongEntries(SongId3& track_id3);
   void RemoveDuplicatedEntries();
   void GetGenreEntry(SongId3& track_id3);
   void GetYearEntry(SongId3& track_id3);
   bool GetFileContent(string file_path, vector<string>& file_content);
   void GetInformationFileContent(SongId3& track_id3);
   bool SortAlbumFiles(SongId3& track_id3);
   void ValidateAlbumTitle(SongId3& track_id3);
   void GetAlbumTitle(SongId3& track_id3);
   void ResetAlbum();
   void ProcessAlbum(const string& album_absolute_path);
   void ProcessAlbums();
   bool GetAlbumsPath();
   void FindUnnecessaryFiles();
   bool IsStringValid(const string& str);
   void ValidateArtistName();
   void GetArtistName();
   void ResetArtist();
   void ProcessArtist();
   void DisplayExample();
   void Print(const string& message = "", bool enable_display = true);
};

#endif