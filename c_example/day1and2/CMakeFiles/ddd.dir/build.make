# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hjpubuntu22045/korea_c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hjpubuntu22045/korea_c

# Include any dependencies generated for this target.
include c_example/day1and2/CMakeFiles/ddd.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include c_example/day1and2/CMakeFiles/ddd.dir/compiler_depend.make

# Include the progress variables for this target.
include c_example/day1and2/CMakeFiles/ddd.dir/progress.make

# Include the compile flags for this target's objects.
include c_example/day1and2/CMakeFiles/ddd.dir/flags.make

c_example/day1and2/CMakeFiles/ddd.dir/ddd.c.o: c_example/day1and2/CMakeFiles/ddd.dir/flags.make
c_example/day1and2/CMakeFiles/ddd.dir/ddd.c.o: c_example/day1and2/ddd.c
c_example/day1and2/CMakeFiles/ddd.dir/ddd.c.o: c_example/day1and2/CMakeFiles/ddd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hjpubuntu22045/korea_c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object c_example/day1and2/CMakeFiles/ddd.dir/ddd.c.o"
	cd /home/hjpubuntu22045/korea_c/c_example/day1and2 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT c_example/day1and2/CMakeFiles/ddd.dir/ddd.c.o -MF CMakeFiles/ddd.dir/ddd.c.o.d -o CMakeFiles/ddd.dir/ddd.c.o -c /home/hjpubuntu22045/korea_c/c_example/day1and2/ddd.c

c_example/day1and2/CMakeFiles/ddd.dir/ddd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ddd.dir/ddd.c.i"
	cd /home/hjpubuntu22045/korea_c/c_example/day1and2 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hjpubuntu22045/korea_c/c_example/day1and2/ddd.c > CMakeFiles/ddd.dir/ddd.c.i

c_example/day1and2/CMakeFiles/ddd.dir/ddd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ddd.dir/ddd.c.s"
	cd /home/hjpubuntu22045/korea_c/c_example/day1and2 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hjpubuntu22045/korea_c/c_example/day1and2/ddd.c -o CMakeFiles/ddd.dir/ddd.c.s

# Object files for target ddd
ddd_OBJECTS = \
"CMakeFiles/ddd.dir/ddd.c.o"

# External object files for target ddd
ddd_EXTERNAL_OBJECTS =

c_example/day1and2/ddd: c_example/day1and2/CMakeFiles/ddd.dir/ddd.c.o
c_example/day1and2/ddd: c_example/day1and2/CMakeFiles/ddd.dir/build.make
c_example/day1and2/ddd: c_example/day1and2/CMakeFiles/ddd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hjpubuntu22045/korea_c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ddd"
	cd /home/hjpubuntu22045/korea_c/c_example/day1and2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ddd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
c_example/day1and2/CMakeFiles/ddd.dir/build: c_example/day1and2/ddd
.PHONY : c_example/day1and2/CMakeFiles/ddd.dir/build

c_example/day1and2/CMakeFiles/ddd.dir/clean:
	cd /home/hjpubuntu22045/korea_c/c_example/day1and2 && $(CMAKE_COMMAND) -P CMakeFiles/ddd.dir/cmake_clean.cmake
.PHONY : c_example/day1and2/CMakeFiles/ddd.dir/clean

c_example/day1and2/CMakeFiles/ddd.dir/depend:
	cd /home/hjpubuntu22045/korea_c && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hjpubuntu22045/korea_c /home/hjpubuntu22045/korea_c/c_example/day1and2 /home/hjpubuntu22045/korea_c /home/hjpubuntu22045/korea_c/c_example/day1and2 /home/hjpubuntu22045/korea_c/c_example/day1and2/CMakeFiles/ddd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : c_example/day1and2/CMakeFiles/ddd.dir/depend

