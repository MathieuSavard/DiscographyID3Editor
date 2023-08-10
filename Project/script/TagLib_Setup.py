import os
import shutil
import subprocess
import platform
import sys

def run_command(command, cwd=None):
    subprocess.run(command, shell=True, cwd=cwd)

def create_directory(directory):
    os.makedirs(directory, exist_ok=True)

def clean_directory(directory):
    if os.path.exists(directory):
        shutil.rmtree(directory, ignore_errors=True)

def configure_and_build_taglib(build_path, install_path, generator):
    cmake_args = [
        "cmake",
        "-B", build_path,
        "-S", TagLibPath,
        "-DCMAKE_INSTALL_PREFIX=" + install_path,
        "-DBUILD_BINDINGS=OFF",
        "-DBUILD_EXAMPLES=OFF",
        "-DBUILD_SHARED_LIBS=OFF",
        "-DBUILD_TESTS=OFF",
        "-DCMAKE_BUILD_TYPE=Release"
        "-DENABLE_CCACHE=OFF"
        "-DENABLE_STATIC_RUNTIME=OFF"
        "-DNO_ITUNES_HACKS=OFF"
        "-DPLATFORM_WINRT=OFF"
        "-DTRACE_IN_RELEASE=OFF"
        "-VISIBILITY_HIDDEN=OFF"
        "-DWITH_ZLIB=OFF"
    ]

    run_command(cmake_args + ["-G", generator], cwd=build_path)
    run_command(["cmake", "--build", build_path])
    run_command(["cmake", "--install", build_path])

if platform.system() == "Windows":
    make_command = "mingw32-make.exe"
    cmake_generator = "MinGW Makefiles"
elif  platform.system() == "Linux":
    make_command = "make"
    cmake_generator = "Unix Makefiles"
else:
    sys.exit()
    
RootPath = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TagLibPath = os.path.join(RootPath, "lib", "id3_editor", "taglib", "taglib")
BuildPath = os.path.join(TagLibPath, "build")
InstallPath = os.path.join(BuildPath, "Install")

clean_directory(TagLibPath)
create_directory(TagLibPath)

run_command(["git", "submodule", "update", "--init"], cwd=TagLibPath)

clean_directory(BuildPath)
create_directory(BuildPath)

configure_and_build_taglib(BuildPath, InstallPath, cmake_generator)
