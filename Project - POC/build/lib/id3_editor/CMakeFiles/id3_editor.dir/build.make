# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Public\Documents\DiscographyID3Editor\Project - POC"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Public\Documents\DiscographyID3Editor\Project - POC\build"

# Include any dependencies generated for this target.
include lib/id3_editor/CMakeFiles/id3_editor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/id3_editor/CMakeFiles/id3_editor.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/id3_editor/CMakeFiles/id3_editor.dir/progress.make

# Include the compile flags for this target's objects.
include lib/id3_editor/CMakeFiles/id3_editor.dir/flags.make

lib/id3_editor/CMakeFiles/id3_editor.dir/itf_id3_editor.cpp.obj: lib/id3_editor/CMakeFiles/id3_editor.dir/flags.make
lib/id3_editor/CMakeFiles/id3_editor.dir/itf_id3_editor.cpp.obj: lib/id3_editor/CMakeFiles/id3_editor.dir/includes_CXX.rsp
lib/id3_editor/CMakeFiles/id3_editor.dir/itf_id3_editor.cpp.obj: C:/Users/Public/Documents/DiscographyID3Editor/Project\ -\ POC/lib/id3_editor/itf_id3_editor.cpp
lib/id3_editor/CMakeFiles/id3_editor.dir/itf_id3_editor.cpp.obj: lib/id3_editor/CMakeFiles/id3_editor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Public\Documents\DiscographyID3Editor\Project - POC\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/id3_editor/CMakeFiles/id3_editor.dir/itf_id3_editor.cpp.obj"
	cd /d C:\Users\Public\Documents\DISCOG~1\PROJEC~1\build\lib\ID3_ED~1 && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/id3_editor/CMakeFiles/id3_editor.dir/itf_id3_editor.cpp.obj -MF CMakeFiles\id3_editor.dir\itf_id3_editor.cpp.obj.d -o CMakeFiles\id3_editor.dir\itf_id3_editor.cpp.obj -c "C:\Users\Public\Documents\DiscographyID3Editor\Project - POC\lib\id3_editor\itf_id3_editor.cpp"

lib/id3_editor/CMakeFiles/id3_editor.dir/itf_id3_editor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/id3_editor.dir/itf_id3_editor.cpp.i"
	cd /d C:\Users\Public\Documents\DISCOG~1\PROJEC~1\build\lib\ID3_ED~1 && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Public\Documents\DiscographyID3Editor\Project - POC\lib\id3_editor\itf_id3_editor.cpp" > CMakeFiles\id3_editor.dir\itf_id3_editor.cpp.i

lib/id3_editor/CMakeFiles/id3_editor.dir/itf_id3_editor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/id3_editor.dir/itf_id3_editor.cpp.s"
	cd /d C:\Users\Public\Documents\DISCOG~1\PROJEC~1\build\lib\ID3_ED~1 && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Public\Documents\DiscographyID3Editor\Project - POC\lib\id3_editor\itf_id3_editor.cpp" -o CMakeFiles\id3_editor.dir\itf_id3_editor.cpp.s

# Object files for target id3_editor
id3_editor_OBJECTS = \
"CMakeFiles/id3_editor.dir/itf_id3_editor.cpp.obj"

# External object files for target id3_editor
id3_editor_EXTERNAL_OBJECTS =

lib/id3_editor/libid3_editor.a: lib/id3_editor/CMakeFiles/id3_editor.dir/itf_id3_editor.cpp.obj
lib/id3_editor/libid3_editor.a: lib/id3_editor/CMakeFiles/id3_editor.dir/build.make
lib/id3_editor/libid3_editor.a: lib/id3_editor/CMakeFiles/id3_editor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\Public\Documents\DiscographyID3Editor\Project - POC\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libid3_editor.a"
	cd /d C:\Users\Public\Documents\DISCOG~1\PROJEC~1\build\lib\ID3_ED~1 && $(CMAKE_COMMAND) -P CMakeFiles\id3_editor.dir\cmake_clean_target.cmake
	cd /d C:\Users\Public\Documents\DISCOG~1\PROJEC~1\build\lib\ID3_ED~1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\id3_editor.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/id3_editor/CMakeFiles/id3_editor.dir/build: lib/id3_editor/libid3_editor.a
.PHONY : lib/id3_editor/CMakeFiles/id3_editor.dir/build

lib/id3_editor/CMakeFiles/id3_editor.dir/clean:
	cd /d C:\Users\Public\Documents\DISCOG~1\PROJEC~1\build\lib\ID3_ED~1 && $(CMAKE_COMMAND) -P CMakeFiles\id3_editor.dir\cmake_clean.cmake
.PHONY : lib/id3_editor/CMakeFiles/id3_editor.dir/clean

lib/id3_editor/CMakeFiles/id3_editor.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Public\Documents\DiscographyID3Editor\Project - POC" "C:\Users\Public\Documents\DiscographyID3Editor\Project - POC\lib\id3_editor" "C:\Users\Public\Documents\DiscographyID3Editor\Project - POC\build" "C:\Users\Public\Documents\DiscographyID3Editor\Project - POC\build\lib\id3_editor" "C:\Users\Public\Documents\DiscographyID3Editor\Project - POC\build\lib\id3_editor\CMakeFiles\id3_editor.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : lib/id3_editor/CMakeFiles/id3_editor.dir/depend

