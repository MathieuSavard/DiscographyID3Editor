import os
import shutil
import subprocess
import platform
import sys

def create_build_directory(path):
    if os.path.exists(path):
        shutil.rmtree(path)
    os.mkdir(path)

def run_command(command, cwd=None):
    subprocess.run(command, shell=True, cwd=cwd)

def main():
    BuildFolderName = "build"
    RootPath = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    BuildPath = os.path.join(RootPath, BuildFolderName)

    if platform.system() == "Windows":
        cmake_command = 'cmake -G "MinGW Makefiles" -B "{}" -S "{}"'.format(BuildPath, RootPath)
        make_command = 'mingw32-make.exe'
    elif platform.system() == "Linux":
        cmake_command = 'cmake -B "{}" -S "{}"'.format(BuildPath, RootPath)
        make_command = 'make'
    else:
        sys.exit()

    create_build_directory(BuildPath)
    
    run_command(cmake_command, cwd=RootPath)
    run_command(make_command, cwd=BuildPath)

if __name__ == "__main__":
    main()
