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
CMAKE_SOURCE_DIR = C:\AllProject\GccProgram\0420\02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\AllProject\GccProgram\0420\02\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/02.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/02.dir/flags.make

CMakeFiles/02.dir/main.c.obj: CMakeFiles/02.dir/flags.make
CMakeFiles/02.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\AllProject\GccProgram\0420\02\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/02.dir/main.c.obj"
	C:\ZyyDownload\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\02.dir\main.c.obj   -c C:\AllProject\GccProgram\0420\02\main.c

CMakeFiles/02.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/02.dir/main.c.i"
	C:\ZyyDownload\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\AllProject\GccProgram\0420\02\main.c > CMakeFiles\02.dir\main.c.i

CMakeFiles/02.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/02.dir/main.c.s"
	C:\ZyyDownload\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\AllProject\GccProgram\0420\02\main.c -o CMakeFiles\02.dir\main.c.s

# Object files for target 02
02_OBJECTS = \
"CMakeFiles/02.dir/main.c.obj"

# External object files for target 02
02_EXTERNAL_OBJECTS =

02.exe: CMakeFiles/02.dir/main.c.obj
02.exe: CMakeFiles/02.dir/build.make
02.exe: CMakeFiles/02.dir/linklibs.rsp
02.exe: CMakeFiles/02.dir/objects1.rsp
02.exe: CMakeFiles/02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\AllProject\GccProgram\0420\02\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 02.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\02.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/02.dir/build: 02.exe

.PHONY : CMakeFiles/02.dir/build

CMakeFiles/02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\02.dir\cmake_clean.cmake
.PHONY : CMakeFiles/02.dir/clean

CMakeFiles/02.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\AllProject\GccProgram\0420\02 C:\AllProject\GccProgram\0420\02 C:\AllProject\GccProgram\0420\02\cmake-build-debug C:\AllProject\GccProgram\0420\02\cmake-build-debug C:\AllProject\GccProgram\0420\02\cmake-build-debug\CMakeFiles\02.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/02.dir/depend

