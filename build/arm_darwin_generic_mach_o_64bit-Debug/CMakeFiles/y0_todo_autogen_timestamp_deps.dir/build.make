# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/y0_/prog/cc/y0_todo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/y0_/prog/cc/y0_todo/build/arm_darwin_generic_mach_o_64bit-Debug

# Utility rule file for y0_todo_autogen_timestamp_deps.

# Include any custom commands dependencies for this target.
include CMakeFiles/y0_todo_autogen_timestamp_deps.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/y0_todo_autogen_timestamp_deps.dir/progress.make

y0_todo_autogen_timestamp_deps: CMakeFiles/y0_todo_autogen_timestamp_deps.dir/build.make
.PHONY : y0_todo_autogen_timestamp_deps

# Rule to build all files generated by this target.
CMakeFiles/y0_todo_autogen_timestamp_deps.dir/build: y0_todo_autogen_timestamp_deps
.PHONY : CMakeFiles/y0_todo_autogen_timestamp_deps.dir/build

CMakeFiles/y0_todo_autogen_timestamp_deps.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/y0_todo_autogen_timestamp_deps.dir/cmake_clean.cmake
.PHONY : CMakeFiles/y0_todo_autogen_timestamp_deps.dir/clean

CMakeFiles/y0_todo_autogen_timestamp_deps.dir/depend:
	cd /Users/y0_/prog/cc/y0_todo/build/arm_darwin_generic_mach_o_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/y0_/prog/cc/y0_todo /Users/y0_/prog/cc/y0_todo /Users/y0_/prog/cc/y0_todo/build/arm_darwin_generic_mach_o_64bit-Debug /Users/y0_/prog/cc/y0_todo/build/arm_darwin_generic_mach_o_64bit-Debug /Users/y0_/prog/cc/y0_todo/build/arm_darwin_generic_mach_o_64bit-Debug/CMakeFiles/y0_todo_autogen_timestamp_deps.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/y0_todo_autogen_timestamp_deps.dir/depend

