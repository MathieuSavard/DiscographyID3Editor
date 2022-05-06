@echo off
:file_beginning
youtube-dl.exe --rm-cache-dir --rm-cache-dir --no-part --download-archive archives.txt --ffmpeg-location "C:/Users/mathi/Desktop/DiscographyID3Editor/youtube-dl/ffmpeg/bin" --extract-audio --audio-format "mp3" -o "C:/Users/mathi/Desktop/DiscographyID3Editor/youtube-dl/Artist/%%(playlist_title)s/%%(playlist_index)s.%%(ext)s" -a playlists.txt
If %ERRORLEVEL% NEQ 0 (
  goto :file_beginning
)