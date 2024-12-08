@echo off
yt-dlp.exe --download-archive downloaded-archive.txt --extract-audio --audio-format "mp3" -o "Artist/%%(playlist_title)s/%%(playlist_index)s.%%(ext)s" -a "playlists.txt"