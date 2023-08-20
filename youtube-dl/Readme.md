==================Windows Installation and User Guide==================
1-Download youtube-dl (https://yt-dl.org/downloads/2021.06.06/youtube-dl.exe)
  It is a simple executable file (.exe) place it in a folder name "youtube-dl"
2-Download ffmpeg (http://www.ffmpeg.org/download.html#build-windows)
  It is a compressed folder. Uncompress it and move it to "youtube-dl" and then rename it to "ffmpeg"
3-Copy/Paste the playlists to download in "playlists.txt"
  Each URL link must be copied on its own line
4-Then run download_playlists.bat
  Either by double clicking on it or by running it in the command prompt

youtube-dl.exe --rm-cache-dir --no-cache-dir --no-part --download-archive archives.txt --ffmpeg-location ".../youtube-dl/ffmpeg/bin" --extract-audio --audio-format "mp3" -o ".../youtube-dl/Artist/%(playlist_title)s/%(playlist_index)s.%(ext)s" -a playlists.txt

[youtube-dl.exe]: Application itself
[--rm-cache-dir]: To avoid 403 error
[--no-part]: Save as ".mp3" file directly, avoiding temporary conversion ".part"
[--download-archive archives.txt]: Archive successful download to avoid redownloading them
[--ffmpeg-location ".../youtube-dl/ffmpeg/bin"]: "ffmpeg" program localisation
[--extract-audio --audio-format "mp3"]: Convert video to ".mp3"
[-o "C:/Users/mathi/Desktop/youtube-dl/%(playlist_title)s/%(playlist_index)s.%(ext)s"]: Download destination
[-a playlists.txt]: File from which playlist URL will be read

["]{1}.*(?=([0-9]{1,2}:[0-9]{2}))