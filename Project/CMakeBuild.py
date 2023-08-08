import os
import shutil
import pathlib

BuildFolderName = "build"
RootFolder = "."

file = pathlib.Path("./build")
if file.exists ():
  shutil.rmtree("./build")
os.mkdir("./build")
os.system('cmake -G "MinGW Makefiles" -B ./build -S .')
os.system('cd ./build && mingw32-make.exe && cd ..')