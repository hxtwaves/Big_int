# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_SOURCE_DIR = /home/hotwaves/git_reps/Big_int/big_int

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hotwaves/git_reps/Big_int/big_int/build

# Include any dependencies generated for this target.
include CMakeFiles/big_nums.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/big_nums.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/big_nums.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/big_nums.dir/flags.make

CMakeFiles/big_nums.dir/big_int.cpp.o: CMakeFiles/big_nums.dir/flags.make
CMakeFiles/big_nums.dir/big_int.cpp.o: /home/hotwaves/git_reps/Big_int/big_int/big_int.cpp
CMakeFiles/big_nums.dir/big_int.cpp.o: CMakeFiles/big_nums.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hotwaves/git_reps/Big_int/big_int/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/big_nums.dir/big_int.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/big_nums.dir/big_int.cpp.o -MF CMakeFiles/big_nums.dir/big_int.cpp.o.d -o CMakeFiles/big_nums.dir/big_int.cpp.o -c /home/hotwaves/git_reps/Big_int/big_int/big_int.cpp

CMakeFiles/big_nums.dir/big_int.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/big_nums.dir/big_int.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hotwaves/git_reps/Big_int/big_int/big_int.cpp > CMakeFiles/big_nums.dir/big_int.cpp.i

CMakeFiles/big_nums.dir/big_int.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/big_nums.dir/big_int.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hotwaves/git_reps/Big_int/big_int/big_int.cpp -o CMakeFiles/big_nums.dir/big_int.cpp.s

CMakeFiles/big_nums.dir/big_double.cpp.o: CMakeFiles/big_nums.dir/flags.make
CMakeFiles/big_nums.dir/big_double.cpp.o: /home/hotwaves/git_reps/Big_int/big_int/big_double.cpp
CMakeFiles/big_nums.dir/big_double.cpp.o: CMakeFiles/big_nums.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hotwaves/git_reps/Big_int/big_int/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/big_nums.dir/big_double.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/big_nums.dir/big_double.cpp.o -MF CMakeFiles/big_nums.dir/big_double.cpp.o.d -o CMakeFiles/big_nums.dir/big_double.cpp.o -c /home/hotwaves/git_reps/Big_int/big_int/big_double.cpp

CMakeFiles/big_nums.dir/big_double.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/big_nums.dir/big_double.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hotwaves/git_reps/Big_int/big_int/big_double.cpp > CMakeFiles/big_nums.dir/big_double.cpp.i

CMakeFiles/big_nums.dir/big_double.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/big_nums.dir/big_double.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hotwaves/git_reps/Big_int/big_int/big_double.cpp -o CMakeFiles/big_nums.dir/big_double.cpp.s

# Object files for target big_nums
big_nums_OBJECTS = \
"CMakeFiles/big_nums.dir/big_int.cpp.o" \
"CMakeFiles/big_nums.dir/big_double.cpp.o"

# External object files for target big_nums
big_nums_EXTERNAL_OBJECTS =

libbig_nums.a: CMakeFiles/big_nums.dir/big_int.cpp.o
libbig_nums.a: CMakeFiles/big_nums.dir/big_double.cpp.o
libbig_nums.a: CMakeFiles/big_nums.dir/build.make
libbig_nums.a: CMakeFiles/big_nums.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hotwaves/git_reps/Big_int/big_int/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libbig_nums.a"
	$(CMAKE_COMMAND) -P CMakeFiles/big_nums.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/big_nums.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/big_nums.dir/build: libbig_nums.a
.PHONY : CMakeFiles/big_nums.dir/build

CMakeFiles/big_nums.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/big_nums.dir/cmake_clean.cmake
.PHONY : CMakeFiles/big_nums.dir/clean

CMakeFiles/big_nums.dir/depend:
	cd /home/hotwaves/git_reps/Big_int/big_int/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hotwaves/git_reps/Big_int/big_int /home/hotwaves/git_reps/Big_int/big_int /home/hotwaves/git_reps/Big_int/big_int/build /home/hotwaves/git_reps/Big_int/big_int/build /home/hotwaves/git_reps/Big_int/big_int/build/CMakeFiles/big_nums.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/big_nums.dir/depend
