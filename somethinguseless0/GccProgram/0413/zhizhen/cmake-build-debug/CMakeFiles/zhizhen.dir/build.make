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
CMAKE_SOURCE_DIR = C:\AllProject\GccProgram\0413\zhizhen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\AllProject\GccProgram\0413\zhizhen\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/zhizhen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zhizhen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zhizhen.dir/flags.make

CMakeFiles/zhizhen.dir/main.c.obj: CMakeFiles/zhizhen.dir/flags.make
CMakeFiles/zhizhen.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\AllProject\GccProgram\0413\zhizhen\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/zhizhen.dir/main.c.obj"
	C:\RuanJian\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\zhizhen.dir\main.c.obj   -c C:\AllProject\GccProgram\0413\zhizhen\main.c

CMakeFiles/zhizhen.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zhizhen.dir/main.c.i"
	C:\RuanJian\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\AllProject\GccProgram\0413\zhizhen\main.c > CMakeFiles\zhizhen.dir\main.c.i

CMakeFiles/zhizhen.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zhizhen.dir/main.c.s"
	C:\RuanJian\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\AllProject\GccProgram\0413\zhizhen\main.c -o CMakeFiles\zhizhen.dir\main.c.s

# Object files for target zhizhen
zhizhen_OBJECTS = \
"CMakeFiles/zhizhen.dir/main.c.obj"

# External object files for target zhizhen
zhizhen_EXTERNAL_OBJECTS =

zhizhen.exe: CMakeFiles/zhizhen.dir/main.c.obj
zhizhen.exe: CMakeFiles/zhizhen.dir/build.make
zhizhen.exe: CMakeFiles/zhizhen.dir/linklibs.rsp
zhizhen.exe: CMakeFiles/zhizhen.dir/objects1.rsp
zhizhen.exe: CMakeFiles/zhizhen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\AllProject\GccProgram\0413\zhizhen\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable zhizhen.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\zhizhen.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zhizhen.dir/build: zhizhen.exe

.PHONY : CMakeFiles/zhizhen.dir/build

CMakeFiles/zhizhen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\zhizhen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/zhizhen.dir/clean

CMakeFiles/zhizhen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\AllProject\GccProgram\0413\zhizhen C:\AllProject\GccProgram\0413\zhizhen C:\AllProject\GccProgram\0413\zhizhen\cmake-build-debug C:\AllProject\GccProgram\0413\zhizhen\cmake-build-debug C:\AllProject\GccProgram\0413\zhizhen\cmake-build-debug\CMakeFiles\zhizhen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zhizhen.dir/depend

