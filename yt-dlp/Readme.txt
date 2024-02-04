================== Windows Installation and User Guide ==================
1-Download yt-dlp (https://github.com/yt-dlp/yt-dlp/releases/download/2023.12.30/yt-dlp.exe)
  It is a simple executable file (.exe) place it in a folder name "yt-dlp"
2-Download ffmpeg (https://www.gyan.dev/ffmpeg/builds/ffmpeg-release-essentials.zip)
  It is a compressed folder. Uncompress it and move it to "yt-dlp" and then rename it to "ffmpeg"
3-Copy/Paste the playlists to download in "playlists.txt"
  Each URL link must be copied on its own line
4-Then run download_playlists.bat
  Either by double clicking on it or by running it in the command prompt

yt-dlp.exe --rm-cache-dir --no-cache-dir --no-part --download-archive archives.txt --ffmpeg-location "ffmpeg/bin" --extract-audio --audio-format "mp3" -o "Artist/%(playlist_title)s/%(playlist_index)s.%(ext)s" -a "playlists.txt"

[yt-dlp.exe]: Application itself
[--rm-cache-dir]: To avoid 403 error
[--no-part]: Save as ".mp3" file directly, avoiding temporary conversion ".part"
[--download-archive archives.txt]: Archive successful download to avoid redownloading them
[--ffmpeg-location "ffmpeg/bin"]: "ffmpeg" program localisation
[--extract-audio --audio-format "mp3"]: Convert video to ".mp3"
[-o "Artist/%(playlist_title)s/%(playlist_index)s.%(ext)s"]: Download destination
[-a "playlists.txt"]: File from which playlist URL will be read