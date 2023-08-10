import os
import shutil
import subprocess
import platform

RootPath = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TagLibPath = os.path.join(RootPath, "lib", "id3_editor", "taglib", "taglib")
BuildPath = os.path.join(TagLibPath, "build")
InstallPath = os.path.join(BuildPath, "Install")

shutil.rmtree(TagLibPath, ignore_errors=True)
os.makedirs(TagLibPath)

subprocess.run(["git", "submodule", "update", "--init"], shell=True, cwd=TagLibPath)

cmake_args = [
    "cmake",
    "-B", BuildPath,
    "-S", TagLibPath,
    "-DCMAKE_INSTALL_PREFIX=" + InstallPath,
    "-DBUILD_BINDINGS=OFF",
    "-DBUILD_EXAMPLES=OFF",
    "-DBUILD_SHARED_LIBS=OFF",
    "-DBUILD_TESTS=OFF",
    "-DCMAKE_BUILD_TYPE=Release",
    "-DWITH_ZLIB=OFF"
]

make_command = "make"
make_install_command = "make install"
cmake_generator = "Unix Makefiles"

if platform.system() == "Windows":
    make_command = "mingw32-make.exe"
    make_install_command = "mingw32-make.exe install"
    cmake_generator = "MinGW Makefiles"

if os.path.exists(BuildPath):
    shutil.rmtree(BuildPath, ignore_errors=True)
os.makedirs(BuildPath)

subprocess.run(cmake_args + ["-G", cmake_generator], shell=True, cwd=BuildPath)
subprocess.run([make_command], shell=True, cwd=BuildPath)
subprocess.run(make_install_command, shell=True, cwd=BuildPath)