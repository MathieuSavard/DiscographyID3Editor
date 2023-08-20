import os
import subprocess
import platform
import sys

if platform.system() == "Windows":
  subprocess.run(["pip", "install", "--upgrade", "youtube-dl"])
  subprocess.run(['pip', 'install', 'ffmpeg-python'])
elif platform.system() == "Linux":
  subprocess.run(["sudo", "pip", "install", "--upgrade", "youtube-dl"])
  subprocess.run(['sudo', 'pip', 'install', 'ffmpeg-python'])
else:
  sys.exit()