# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\RuanJian\CLion\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\RuanJian\CLion\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\AllProject\GccProgram\0420\test03

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\AllProject\GccProgram\0420\test03\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test03.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test03.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test03.dir/flags.make

CMakeFiles/test03.dir/main.cpp.obj: CMakeFiles/test03.dir/flags.make
CMakeFiles/test03.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\AllProject\GccProgram\0420\test03\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test03.dir/main.cpp.obj"
	C:\ZyyDownload\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test03.dir\main.cpp.obj -c C:\AllProject\GccProgram\0420\test03\main.cpp

CMakeFiles/test03.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test03.dir/main.cpp.i"
	C:\ZyyDownload\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\AllProject\GccProgram\0420\test03\main.cpp > CMakeFiles\test03.dir\main.cpp.i

CMakeFiles/test03.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test03.dir/main.cpp.s"
	C:\ZyyDownload\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\AllProject\GccProgram\0420\test03\main.cpp -o CMakeFiles\test03.dir\main.cpp.s

# Object files for target test03
test03_OBJECTS = \
"CMakeFiles/test03.dir/main.cpp.obj"

# External object files for target test03
test03_EXTERNAL_OBJECTS =

test03.exe: CMakeFiles/test03.dir/main.cpp.obj
test03.exe: CMakeFiles/test03.dir/build.make
test03.exe: CMakeFiles/test03.dir/linklibs.rsp
test03.exe: CMakeFiles/test03.dir/objects1.rsp
test03.exe: CMakeFiles/test03.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\AllProject\GccProgram\0420\test03\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test03.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test03.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test03.dir/build: test03.exe

.PHONY : CMakeFiles/test03.dir/build

CMakeFiles/test03.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test03.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test03.dir/clean

CMakeFiles/test03.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\AllProject\GccProgram\0420\test03 C:\AllProject\GccProgram\0420\test03 C:\AllProject\GccProgram\0420\test03\cmake-build-debug C:\AllProject\GccProgram\0420\test03\cmake-build-debug C:\AllProject\GccProgram\0420\test03\cmake-build-debug\CMakeFiles\test03.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test03.dir/depend

