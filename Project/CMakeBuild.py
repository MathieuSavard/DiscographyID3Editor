import os
import shutil
import pathlib

BuildFolderName = "Builds"
RootFolder = "."

file = pathlib.Path("./Builds")
if file.exists ():
  shutil.rmtree("./Builds")
os.mkdir("./Builds")
os.system('cmake -G "MinGW Makefiles" -B ./Builds -S .')
os.system('cd ./Builds && mingw32-make.exe && cd ..')