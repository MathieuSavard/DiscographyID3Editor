# Windows Installation and User Guide

## Step 1: Download Necessary Tools
1. **[yt-dlp](https://github.com/yt-dlp/yt-dlp/releases)**
   - Download the executable file (`yt-dlp.exe`) and place it in the root folder of your project.

2. **[FFmpeg](https://www.gyan.dev/ffmpeg/builds/ffmpeg-release-essentials.zip)**
   - Download the compressed folder.
   - Extract it, locate `ffmpeg.exe`, and move the executable to the root folder.

## Step 2: Prepare the Playlist
- Create a file named `playlists.txt` in the root folder.
- Copy and paste YouTube playlist URLs into `playlists.txt`.
  - **Note**: Each URL should be on a separate line.

## Step 3: Run the Batch File
- Execute `download_playlists.bat` to start downloading videos from the playlists.

## Step 4: Edit Metadata
- Download and install **[MusicBrainz Picard](https://picard.musicbrainz.org/downloads)**.
- Open Picard:
  - Either double-click its shortcut or run it from the command prompt.
- Use Picard to edit the metadata of the downloaded files.
