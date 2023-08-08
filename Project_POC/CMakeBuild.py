import os
import shutil
import subprocess

BuildFolderName = "build"
RootPath = os.path.dirname(os.path.abspath(__file__))
BuildPath = os.path.join(RootPath, BuildFolderName)
#if os.path.exists(BuildPath):
#        shutil.rmtree(BuildPath)
# os.mkdir(BuildPath)


if os.name == 'nt':
    cmake_command = 'cmake -G "MinGW Makefiles" -B "{}" -S "{}"'.format(BuildPath, RootPath)
    make_command = 'mingw32-make.exe'
else:
    cmake_command = 'cmake -B "{}" -S "{}"'.format(BuildPath, RootPath)
    make_command = 'make'

subprocess.run(cmake_command, shell=True, cwd=RootPath)
subprocess.run(make_command, shell=True, cwd=BuildPath)