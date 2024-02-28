import os
import shutil
import subprocess
import platform
import sys

def run_command(command, cwd=None):
    subprocess.run(command, shell=True, cwd=cwd)

def main():
    BuildFolderName = "build"
    RootPath = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    BuildPath = os.path.join(RootPath, BuildFolderName)

    if platform.system() == "Windows":
        make_command = 'mingw32-make.exe'
    elif platform.system() == "Linux":
        make_command = 'make'
    else:
        sys.exit()
    
    run_command(make_command, cwd=BuildPath)

if __name__ == "__main__":
    main()
