#include <fstream>
#include <algorithm>
#include <iostream>

#include "./app.hpp"

void Application::EditId3s() {
  string current_albums_title = {};
  string album_absolute_path = "";
 
  Print();

  if (song_id3s.size() == 0) {
    Print("Error: no files to edit");
    return;
  }

  Print(song_id3s.at(0).artist_name);

  for (uint32_t i = 0; i < song_id3s.size(); i++) {
    if (current_albums_title != song_id3s.at(i).album_title) {
      current_albums_title = song_id3s.at(i).album_title;
      Print("\t" + current_albums_title);
    }

    id3_editor->EditID3(artist_absolute_path + path_slash_separator + song_id3s.at(i).album_title + path_slash_separator + to_string(song_id3s.at(i).track) + "." + song_file_extension, song_id3s.at(i));

    Print("\t\t" + song_id3s.at(i).title + "." + song_file_extension);
  }
}

void Application::PrintUnnecessaryDirectory(SongId3& song_id3) {
  string unnecessary_folder_name = "";
  vector<string> unnecessary_folders = {};

  if (!file_system->GetDirectories(album_absolute_path, unnecessary_folders)) {
    is_valid = false;
    Print("\t\tError: failed get the list of directories in: \"" + album_absolute_path + "\"", display_errors);
    return;
  }

  for (uint32_t i = 0; i < unnecessary_folders.size(); i++) {
    is_valid = false;
    if (!file_system->GetDirectoryName(unnecessary_folders.at(i), unnecessary_folder_name)) {
      Print("\t\tError: unnecessary directory found: \"" + unnecessary_folders.at(i) + "\"", display_errors);
      continue;
     }

    Print("\t\tError: unnecessary directory found: \"" + unnecessary_folder_name + "\"", display_errors);
  }
}

void Application::PrintUnnecessaryFiles() {
  string unnecessary_file_name = "";
  string extension = "";

  unnecessary_files.insert(unnecessary_files.begin(), song_files.begin(), song_files.end());

  if(unnecessary_files.size() > 0)
    is_valid = false;
  
  for (uint32_t i = 0; i < unnecessary_files.size(); i++) {
    unnecessary_file_name = "";
    extension = "";

    if (!file_system->GetFileName(unnecessary_files.at(i), unnecessary_file_name)) {
      Print("\t\tError: unnecessary file found: \"" + unnecessary_files.at(i) + "\"", display_errors);
      continue;
    }

    if (!file_system->GetFileExtension(unnecessary_files.at(i), extension)) {
      Print("\t\tError: unnecessary file found: \"" + unnecessary_files.at(i) + "\"", display_errors);
      continue;
    }

    if (extension != "") {
      extension = "." + extension;
    }

    Print("\t\tError: unnecessary file found: \"" + unnecessary_file_name + extension + "\"", display_errors);
  } 
}

bool Application::ValidateDuration(const string& entry, const SongId3& song_id3, const string& duration_string) {
  const uint32_t second_position = 0;
  const uint32_t minute_position = 1;
  const uint32_t hour_position = 2;
  const uint32_t day_position = 3;
  const uint32_t maximum_fields = 4;
  const uint32_t seconds_in_minute = 60;
  const uint32_t seconds_in_hour = 3600;
  const uint32_t seconds_in_day = 86400;
  const uint32_t uncertainty_seconds = 1;
  const double uncertainty_percentage = 0.01;

  string modifiable_duration = duration_string;
  vector<string> duration_section = {};
  uint32_t entry_duration = 0;
  uint32_t file_duration = 0;

  while (modifiable_duration.find_first_of(duration_separator) != string::npos) {
    duration_section.push_back(modifiable_duration.substr(modifiable_duration.find_last_of(duration_separator) + duration_separator.size(), modifiable_duration.size() - modifiable_duration.find_last_of(duration_separator)));
    modifiable_duration = modifiable_duration.substr(0, modifiable_duration.find_last_of(duration_separator));
  }

  duration_section.push_back(modifiable_duration);

  if (duration_section.size() > maximum_fields) {
    is_valid = false;
    Print("\t\tError: entry's duration is not valid: \"" + duration_string + "\"", display_errors);
    return false;
  }

  for (uint32_t i = 0; i < duration_section.size(); i++) {
    for (uint32_t j = 0; j < duration_section.at(i).size(); j++) {
      if (isdigit(duration_section.at(i).at(j)) == false) {
        is_valid = false;
        Print("\t\tError: entry's duration must be an unsigned integer: \"" + entry + "\"", display_errors);
        return false;
      }
    }
  }

  for (uint32_t i = 0; i < duration_section.size(); i++) {
    if (i == second_position)
      entry_duration += stoi(duration_section.at(i));
    if (i == minute_position)
      entry_duration += seconds_in_minute * stoi(duration_section.at(i));
    if (i == hour_position)
      entry_duration += seconds_in_hour * stoi(duration_section.at(i));
    if (i == day_position)
      entry_duration += seconds_in_day * stoi(duration_section.at(i));
  }

  file_duration = id3_editor->GetDuration(artist_absolute_path + path_slash_separator + song_id3.album_title + path_slash_separator + to_string(song_id3.track) + "." + song_file_extension);

  if ((file_duration <= entry_duration - entry_duration * uncertainty_percentage - uncertainty_seconds) || 
      (file_duration >= entry_duration + entry_duration * uncertainty_percentage + uncertainty_seconds)) {
    is_valid = false;
    Print("\t\tError: entry duration \"" + to_string(entry_duration) + " seconds\" and file duration \"" + to_string(file_duration) + " seconds\" of " + entry + " mismatch", display_errors);
    return false;
  }

  return true;
}

bool Application::RemoveExistingSong(const SongId3& song_id3) {
  bool track_exist = false; 

  if (find(song_files.begin(), song_files.end(), album_absolute_path + path_slash_separator + to_string(song_id3.track) + "." + song_file_extension) != song_files.end())
    track_exist = true;

  if (!track_exist) {
    is_valid = false;
    Print("\t\tError: Track file not found: \"" + to_string(song_id3.track) + "." + song_file_extension + "\"", display_errors);
    return false;
   }

  for (uint32_t i = 0; i < song_files.size(); i++)
    if (song_files.at(i) == album_absolute_path + path_slash_separator + to_string(song_id3.track) + "." + song_file_extension) {
      song_files.erase(song_files.begin() + i);
      break;
    }

   return true;
}

void Application::ValidateTitle(const string& title) {
  if (!IsStringValid(title)) {
    is_valid = false;
    Print("\t\tError: Song title have unsupported character(s): \"" + title + "\"", display_errors);
  }
}

void Application::ValidateTrack(const string& track) {
  string second_track_name = "";
  uint32_t occurence_count = 0;

  for (uint32_t j = 0; j < track.size(); j++)
    if (isdigit(track.at(j)) == false) {
      is_valid = false;
      Print("\t\tError: entry's track must be an unsigned integer: \"" + track + "\"", display_errors);
      return;
    }

  for (uint32_t i = 0; i < album_information_file_content.size(); i++) {
    second_track_name = album_information_file_content.at(i).substr(0, album_information_file_content.at(i).find(track_title_duration_separator));
    if (second_track_name == track)
      occurence_count++;
  }  

  if (occurence_count > 1) {
    is_valid = false;
    Print("\t\tError: " + to_string(occurence_count) + " occurence of track \"" + track + "\" where found in album information file");
    return;
  }

  // Vérifier si seulement un fichier "track".mp3 existe
}

bool Application::GetEntryFields(const string& entry, string& track_name, string& title_name, string& duration_string) {
  size_t first_occurence = 0;
  size_t last_occurence = 0;

  if (entry.find(track_title_duration_separator) == string::npos) {
    is_valid = false;
    Print("\t\tError: cannot find any separator \"" + track_title_duration_separator + "\" in information file entry: \"" + entry + "\"", display_errors);
    return false;
  }

  first_occurence = entry.find_first_of(track_title_duration_separator);
  last_occurence = entry.find_last_of(track_title_duration_separator);

  if (first_occurence == last_occurence) {
    is_valid = false;
    Print("\t\tError: cannot find second separator \"" + track_title_duration_separator + "\" in information file entry: \"" + entry + "\"", display_errors);
    return false;
  }

  track_name = entry.substr(0, first_occurence);
  title_name = entry.substr(first_occurence + track_title_duration_separator.size(), last_occurence - (first_occurence + track_title_duration_separator.size()));
  duration_string = entry.substr(last_occurence + track_title_duration_separator.size(), entry.size() - last_occurence);

  return true;
}

void Application::ValidateSongEntries(SongId3& song_id3) {
  string track = "";
  string title = "";
  string duration = "";

  for (uint32_t i = 0; i < album_information_file_content.size(); i++) {
    track = "";
    title = "";
    duration = "";

    if (!GetEntryFields(album_information_file_content.at(i), track, title, duration))
      continue; 

    ValidateTrack(track);

    ValidateTitle(title);

    song_id3.track = stoi(track);
    song_id3.title = title;

    if (!RemoveExistingSong(song_id3))
      continue;
 
    if (!ValidateDuration(album_information_file_content.at(i), song_id3, duration))
      continue;

    song_id3s.push_back(song_id3);
  }
}

void Application::RemoveDuplicatedEntries() {
  if (album_information_file_content.size() > 1) {
    for (uint32_t i = 0; i < album_information_file_content.size() - 1; i++) {
      for (uint32_t j = i + 1; j < album_information_file_content.size(); j++) {
        if (album_information_file_content.at(j) == album_information_file_content.at(i)) {
          is_valid = false;
          album_information_file_content.erase(album_information_file_content.begin() + j);
          j--;
          Print("\t\tError: information file contains 2 identical entries: \"" + album_information_file_content.at(j) + "\"", display_errors);
        }
      }
    }
  }
}

void Application::GetGenreEntry(SongId3& song_id3) {
  string album_genre = "";

  if (album_information_file_content.size() <= 0) {
    is_valid = false;
    Print("\t\tError: information file's genre entry is missing", display_errors);
    return;
  }

  album_genre = album_information_file_content.at(0);
  album_information_file_content.erase(album_information_file_content.begin());

  if (album_genre == "") {
    is_valid = false;
    Print("\t\tError: information file's genre entry is empty", display_errors);
    return;
  }

  song_id3.album_genre = album_genre;
}

void Application::GetYearEntry(SongId3& song_id3) {
  string album_year = "";

  if (album_information_file_content.size() <= 0) {
    is_valid = false;
    Print("\t\tError: information file's year entry is missing", display_errors);
    return;
  }

  album_year = album_information_file_content.at(0);
  album_information_file_content.erase(album_information_file_content.begin());

  if (album_year == "") {
    is_valid = false;
    Print("\t\ttError: information file's year entry is empty", display_errors);
    return;
  }

  for (uint32_t i = 0; i < album_year.size(); i++) {
    if (isdigit(album_year.at(i)) == false) {
      is_valid = false;
      Print("\t\tError: information file's year entry must be an unsigned integer: \"" + album_year + "\"", display_errors);
      return;
    }
  }
    
  song_id3.album_year = stoi(album_year);
}

bool Application::GetFileContent(string file_path, vector<string>& file_content) {
  fstream file_stream = {};

  file_stream.open(file_path, ios::in);

  if (!file_stream.is_open()) {
    return false;
  } else {
    string file_line = "";
    while (getline(file_stream, file_line)) {
      while (file_line.find('\r') != string::npos)
        file_line.erase(file_line.find('\r'), sizeof('\r'));
      while (file_line.find('\n') != string::npos)
        file_line.erase(file_line.find('\n'), sizeof('\n'));
      while (file_line.find('\t') != string::npos)
        file_line.erase(file_line.find('\t'), sizeof('\t'));

      file_content.push_back(file_line);
    }
    file_stream.close();
  }
 
  return true;
}

void Application::GetInformationFileContent(SongId3& song_id3) {
  string information_file_name = song_id3.album_title + "." + information_file_extension;
  string information_file_path = album_absolute_path + path_slash_separator + information_file_name;

  if (!file_system->Exist(information_file_path)) {
    is_valid = false;
    Print("\t\tError: Album informtaion file does not exist: \"" + information_file_name + "\"", display_errors);
    return;
  }

  if (!file_system->IsFile(information_file_path)) {
    is_valid = false;
    Print("\t\tError: Album informtaion file is not a file: \"" + information_file_name + "\"", display_errors);
    return;
  }

  if (!GetFileContent(information_file_path, album_information_file_content)) {
    is_valid = false;
    Print("\t\tError: cannot get the content of information file: \"" + information_file_name + "\"", display_errors);
    return;
  }
}

bool Application::SortAlbumFiles(SongId3& song_id3) {
  bool album_contain_information_file = false;
  bool album_contain_cover_file = false;
  vector<string> files = {};
  string file_name = "";
  string file_extension = "";

  if (!file_system->GetFiles(album_absolute_path, files)) {
    is_valid = false;
    Print("\t\tError: failed get the list of files in: \"" + album_absolute_path + "\"", display_errors);
    return false;
  }

  if(files.size() <= 0) {
    is_valid = false;
    Print("\t\tError: no files found in : \"" + album_absolute_path + "\"", display_errors);
    return false;
  }

  for (uint32_t i = 0; i < files.size(); i++) {
    if (!file_system->GetFileName(files.at(i), file_name)) {
      is_valid = false;
      Print("\t\tError: failed to get the file name of: \"" + files.at(i) + "\"", display_errors);
      unnecessary_files.push_back(files.at(i));
      continue;
    }

    if (!file_system->GetFileExtension(files.at(i), file_extension)) {
      is_valid = false;
      Print("\t\tError: failed to get the file extension of: \"" + files.at(i) + "\"", display_errors);
      unnecessary_files.push_back(files.at(i));
      continue;
    }

    file_extension = "." + file_extension;

    if (file_name + file_extension == song_id3.album_title + "." + information_file_extension)
      album_contain_information_file = true;
    else if (file_name + file_extension == song_id3.album_title + "." + album_cover_file_extension) {
      album_contain_cover_file = true;
      song_id3.album_cover_path = album_absolute_path + path_slash_separator + song_id3.album_title + "." + album_cover_file_extension;
    }
    else if (file_extension == "." + song_file_extension)
      song_files.push_back(files.at(i));
    else
      unnecessary_files.push_back(files.at(i));
  }

  if (!album_contain_information_file) {
    is_valid = false;
    Print("\t\tError: no information file found: \"" + song_id3.album_title + "." + information_file_extension + "\"", display_errors);
  }

  if (!album_contain_cover_file) {
    is_valid = false;
    Print("\t\tError: no cover art file found: \"" + song_id3.album_title + "." + album_cover_file_extension + "\"", display_errors);
  }

  if (song_files.size() <= 0) {
    is_valid = false;
    Print("\t\tError: no \"." + song_file_extension + "\" file found", display_errors);
  }

  for (uint32_t i = 0; i < unnecessary_files.size(); i++) {
    is_valid = false;
    Print("\t\tError: unnecessary files found: \"" + unnecessary_files.at(i) + "\"", display_errors);
  }

  if (!album_contain_information_file || !album_contain_cover_file || song_files.size() <= 0 || unnecessary_files.size() > 0)
    return false;

  return true;
}

void Application::ValidateAlbumTitle(SongId3& song_id3) {
  if (!IsStringValid(song_id3.album_title)) {
    is_valid = false;
    Print("\t\tError: Album title have unsupported character(s): \"" + song_id3.album_title + "\"", display_errors);
  }
}

void Application::GetAlbumTitle(SongId3& song_id3) {
  if (!file_system->GetDirectoryName(album_absolute_path, song_id3.album_title)) {
    is_valid = false;
    Print("\t" + album_absolute_path, display_errors);
    Print("\t\tError: failed to get the album title from the album absolute path: \"" + album_absolute_path + "\"", display_errors);
    return;
  }

  Print("\t" + song_id3.album_title, display_errors);
}

void Application::ResetAlbum() {
  album_absolute_path = "";
  album_information_file_content.clear();
  song_files.clear();
  unnecessary_files.clear();
}

void Application::ProcessAlbum(const string& album_absolute_path) {
  SongId3 song_id3 = {};
  
  ResetAlbum();

  song_id3.artist_name = artist_name;
  
  this->album_absolute_path = album_absolute_path;

  GetAlbumTitle(song_id3);

  ValidateAlbumTitle(song_id3);

  if (!SortAlbumFiles(song_id3))
    return;

  GetInformationFileContent(song_id3);

  GetYearEntry(song_id3);

  GetGenreEntry(song_id3);

  RemoveDuplicatedEntries();

  ValidateSongEntries(song_id3);

  PrintUnnecessaryFiles();

  PrintUnnecessaryDirectory(song_id3);
}

void Application::ProcessAlbums() {
  Print("", display_errors);

  for (uint32_t i = 0; i < album_absolute_paths.size(); i++) {
    ProcessAlbum(album_absolute_paths.at(i));
    if(i < album_absolute_paths.size() - 1)
        Print("", display_errors);
  }
}

bool Application::GetAlbumsPath() {
  if (!file_system->GetDirectories(artist_absolute_path, album_absolute_paths)) {
    is_valid = false;
    Print("\tError: failed get the list of directories in: \"" + artist_absolute_path + "\"", display_errors);
    return false;
  }

  if (album_absolute_paths.size() <= 0) {
    is_valid = false;
    Print("\tError: artist directory does not contains any album directories: \"" + artist_absolute_path + "\"", display_errors);
    return false;
  }

  return true;
}

void Application::FindUnnecessaryFiles() {
  vector<string> unnecessary_files = {};
  string unnecessary_file_name = "";

  if (!file_system->GetFiles(artist_absolute_path, unnecessary_files)) {
    is_valid = false;
    Print("\tError: failed get the list of files in: \"" + artist_absolute_path + "\"", display_errors);
    return;
  }

  if (unnecessary_files.size() > 0)
    is_valid = false;

  for (uint32_t i = 0; i < unnecessary_files.size(); i++)
    if (file_system->GetFileName(unnecessary_files.at(i), unnecessary_file_name))
      Print("\tError: unnecessary file found in artist directory: \"" + unnecessary_file_name + "\"", display_errors);
    else
      Print("\tError: unnecessary file found in artist directory: \"" + unnecessary_files.at(i) + "\"", display_errors);
}

bool Application::IsStringValid(const string& str) {
  bool is_found = false;

  vector<int> valid_chars = {' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 
                             'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 
                             'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~'};

  for (uint32_t i = 0; i < str.size(); i++) {
    is_found = false;

    for (uint32_t j = 0; j < valid_chars.size(); j++)
      if (str.at(i) == valid_chars.at(j)) {
        is_found = true;
        break;
      }
    
    if (!is_found)
      return false;
  }

  return true;
}

void Application::ValidateArtistName() {
  if(!IsStringValid(artist_name)) {
    is_valid = false;
    Print("\tError: Artist name have unsupported character(s): \"" + artist_name + "\"", display_errors);
  }
}

void Application::GetArtistName() {
  if (!file_system->GetDirectoryName(artist_absolute_path, artist_name)) {
    is_valid = false;
    Print("Error: failed to get the artist directory name from the artist absolute path: \"" + artist_absolute_path + "\"", display_errors);
    return;
  }

  Print(artist_name, display_errors);
}

void Application::ResetArtist() {
  is_valid = true;
  artist_name = "";
  album_absolute_paths.clear();
  song_id3s.clear();
  
  ResetAlbum();
}

void Application::ProcessArtist() {
  ResetArtist();

  GetArtistName();

  ValidateArtistName();

  FindUnnecessaryFiles();

  if (!GetAlbumsPath())
    return;

  ProcessAlbums();

  if (is_valid && edit_id3)
    EditId3s();
}

void Application::DisplayExample() {
  Print("/****Artist Folder Structure***\\");
  Print("Mayhem/");
  Print("\tDe Mysteriis Dom Sathanas/");
  Print("\t\tDe Mysteriis Dom Sathanas." + information_file_extension);
  Print("\t\tDe Mysteriis Dom Sathanas." + album_cover_file_extension);
  Print("\t\t1." + song_file_extension);
  Print("\t\t2." + song_file_extension);
  Print("\t\t3." + song_file_extension);
  Print("\t\t4." + song_file_extension);
  Print("\t\t5." + song_file_extension);
  Print("\t\t6." + song_file_extension);
  Print("\t\t7." + song_file_extension);
  Print("\t\t8." + song_file_extension);
  Print("\tGrand Declaration of War");
  Print("\t\t...");
  Print("\t\t...");
  Print("\t\t...");
  Print("\t...");
  Print("\t\t...");
  Print("\t\t...");
  Print("\t\t...");
  Print("/******************************\\");
  Print();

  Print("/*****De Mysteriis Dom Sathanas." + information_file_extension + " File Content*****\\");
  Print("\"1994\"");
  Print("\"Black Metal\"");
  Print("1" + track_title_duration_separator + "Funeral Fog" + track_title_duration_separator + "5" + duration_separator + "47");
  Print("2" + track_title_duration_separator + "Freezing Moon" + track_title_duration_separator + "6" + duration_separator + "23");
  Print("3" + track_title_duration_separator + "Cursed In Eternity" + track_title_duration_separator + "5" + duration_separator + "10");
  Print("4" + track_title_duration_separator + "Pagan Fears" + track_title_duration_separator + "6" + duration_separator + "20");
  Print("5" + track_title_duration_separator + "Life Eternal" + track_title_duration_separator + "6" + duration_separator + "57");
  Print("6" + track_title_duration_separator + "From The Dark Past" + track_title_duration_separator + "5" + duration_separator + "26");
  Print("7" + track_title_duration_separator + "Buried By Time And Dust" + track_title_duration_separator + "3" + duration_separator + "34");
  Print("8" + track_title_duration_separator + "De Mysteriis Dom Sathanas" + track_title_duration_separator + "6" + duration_separator + "21");
  Print("/******************************\\");
}

void Application::Print(const string& message, bool enable_display) {
  if (enable_display)
    cout << message << endl;
}

int Application::Start() {
  string user_selection = "";

  while (1) {
    if (artist_absolute_path == "")
      Print("Registered Artist Path: \"*No Artist Path Register*\"");
    else
      Print("Registered Artist Path: \"" + artist_absolute_path + "\"");

    if (display_errors)
      Print("Error display: Enable");
    else
      Print("Error display: Disable");

    if (edit_id3)
      Print("ID3 edition: Enable");
    else
      Print("ID3 edition: Disable");

    Print("1-Set the artist absolute path");
    Print("2-Display information file example");
    Print("3-Toggle errors display");
    Print("4-Toggle song's ID3 edition");
    Print("5-Process artist");
    Print("6-Exit application");

    getline(cin, user_selection);

    if (user_selection.size() > 0) {

      Print();

      switch (user_selection.at(0)) {
      case '1':
        Print("Enter a valid artist path:");
        getline(cin, artist_absolute_path);
        replace(artist_absolute_path.begin(), artist_absolute_path.end(), '\\', '/');

        if (!file_system->Exist(artist_absolute_path)) {
          Print("Artist path does not exist: \"" + artist_absolute_path + "\"");
          artist_absolute_path = "";
          break;
        }

        if (!file_system->IsDirectory(artist_absolute_path)) {
          Print("Artist path is not a directory: \"" + artist_absolute_path + "\"");
          artist_absolute_path = "";
          break;
        }
        break;

      case '2':
        DisplayExample();
        break;

      case '3':
        if (display_errors)
          display_errors = false;
        else
          display_errors = true;
        break;

      case '4':
        if (edit_id3)
          edit_id3 = false;
        else
          edit_id3 = true;
        break;

      case '5':
        if (artist_absolute_path != "") {
          if (display_errors || edit_id3)
            ProcessArtist();
          else
            Print("No action to perform: \"Error display\" and  \"ID3 edition\" are disabled");
        }
        else
          Print("Enter a valid artist path to proceed" + artist_absolute_path);
        break;

      case '6':
        return 0;
        break;

      case '\0':
        break;

      default:
        Print("Invalid option");
      }

      Print();
    }

    user_selection = "";
  }
}

Application::Application(ItfId3Editor* id3_editor, ItfFileSystem* file_system) {
  this->id3_editor = id3_editor;
  this->file_system = file_system;
}
