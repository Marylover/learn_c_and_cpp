# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/CLion-2018.2.2/clion-2018.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /usr/local/CLion-2018.2.2/clion-2018.2.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dong/CLionProjects/read_file

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dong/CLionProjects/read_file/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/read_file.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/read_file.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/read_file.dir/flags.make

CMakeFiles/read_file.dir/main.cpp.o: CMakeFiles/read_file.dir/flags.make
CMakeFiles/read_file.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/CLionProjects/read_file/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/read_file.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/read_file.dir/main.cpp.o -c /home/dong/CLionProjects/read_file/main.cpp

CMakeFiles/read_file.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/read_file.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/CLionProjects/read_file/main.cpp > CMakeFiles/read_file.dir/main.cpp.i

CMakeFiles/read_file.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/read_file.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/CLionProjects/read_file/main.cpp -o CMakeFiles/read_file.dir/main.cpp.s

# Object files for target read_file
read_file_OBJECTS = \
"CMakeFiles/read_file.dir/main.cpp.o"

# External object files for target read_file
read_file_EXTERNAL_OBJECTS =

read_file: CMakeFiles/read_file.dir/main.cpp.o
read_file: CMakeFiles/read_file.dir/build.make
read_file: CMakeFiles/read_file.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dong/CLionProjects/read_file/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable read_file"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/read_file.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/read_file.dir/build: read_file

.PHONY : CMakeFiles/read_file.dir/build

CMakeFiles/read_file.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/read_file.dir/cmake_clean.cmake
.PHONY : CMakeFiles/read_file.dir/clean

CMakeFiles/read_file.dir/depend:
	cd /home/dong/CLionProjects/read_file/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dong/CLionProjects/read_file /home/dong/CLionProjects/read_file /home/dong/CLionProjects/read_file/cmake-build-debug /home/dong/CLionProjects/read_file/cmake-build-debug /home/dong/CLionProjects/read_file/cmake-build-debug/CMakeFiles/read_file.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/read_file.dir/depend

