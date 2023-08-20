import subprocess
import os

download_folder = "C:/Users/Public/Documents/DiscographyID3Editor/youtube-dl"

with open("C:/Users/Public/Documents/DiscographyID3Editor/youtube-dl/playlists.txt", "r") as playlists_file:
    playlists = playlists_file.readlines()

while True:
    try:
        for playlist in playlists:
            playlist = playlist.strip()
            command = [
                "youtube-dl",
                "--rm-cache-dir",
                "--no-part",
                "--download-archive",
                "C:/Users/Public/Documents/DiscographyID3Editor/youtube-dl/archives.txt",
                "--extract-audio",
                "--audio-format",
                "mp3",
                "-o",
                os.path.join(download_folder, "%(playlist_title)s", "%(playlist_index)s.%(ext)s"),
                "-a",
                playlist
            ]
            result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, shell=True)
            
            if result.returncode != 0:
                print("Error downloading playlist:", playlist)
                print("Retrying...")
            
            print("Playlist downloaded:", playlist)
        
        break  # Exit the loop if all playlists were downloaded successfully
    except KeyboardInterrupt:
        print("Download interrupted by user.")
        break
    except Exception as e:
        print("An error occurred:", str(e))
        break
