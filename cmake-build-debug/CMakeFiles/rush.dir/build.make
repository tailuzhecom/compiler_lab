# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/young/下载/CLion-2019.2.5/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/young/下载/CLion-2019.2.5/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/young/文档/编译工程/lab/lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/young/文档/编译工程/lab/lab2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rush.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rush.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rush.dir/flags.make

CMakeFiles/rush.dir/cgen.cpp.o: CMakeFiles/rush.dir/flags.make
CMakeFiles/rush.dir/cgen.cpp.o: ../cgen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/young/文档/编译工程/lab/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rush.dir/cgen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rush.dir/cgen.cpp.o -c /home/young/文档/编译工程/lab/lab2/cgen.cpp

CMakeFiles/rush.dir/cgen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rush.dir/cgen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/young/文档/编译工程/lab/lab2/cgen.cpp > CMakeFiles/rush.dir/cgen.cpp.i

CMakeFiles/rush.dir/cgen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rush.dir/cgen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/young/文档/编译工程/lab/lab2/cgen.cpp -o CMakeFiles/rush.dir/cgen.cpp.s

CMakeFiles/rush.dir/parser.tab.cpp.o: CMakeFiles/rush.dir/flags.make
CMakeFiles/rush.dir/parser.tab.cpp.o: ../parser.tab.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/young/文档/编译工程/lab/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rush.dir/parser.tab.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rush.dir/parser.tab.cpp.o -c /home/young/文档/编译工程/lab/lab2/parser.tab.cpp

CMakeFiles/rush.dir/parser.tab.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rush.dir/parser.tab.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/young/文档/编译工程/lab/lab2/parser.tab.cpp > CMakeFiles/rush.dir/parser.tab.cpp.i

CMakeFiles/rush.dir/parser.tab.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rush.dir/parser.tab.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/young/文档/编译工程/lab/lab2/parser.tab.cpp -o CMakeFiles/rush.dir/parser.tab.cpp.s

CMakeFiles/rush.dir/scanner.cpp.o: CMakeFiles/rush.dir/flags.make
CMakeFiles/rush.dir/scanner.cpp.o: ../scanner.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/young/文档/编译工程/lab/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/rush.dir/scanner.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rush.dir/scanner.cpp.o -c /home/young/文档/编译工程/lab/lab2/scanner.cpp

CMakeFiles/rush.dir/scanner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rush.dir/scanner.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/young/文档/编译工程/lab/lab2/scanner.cpp > CMakeFiles/rush.dir/scanner.cpp.i

CMakeFiles/rush.dir/scanner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rush.dir/scanner.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/young/文档/编译工程/lab/lab2/scanner.cpp -o CMakeFiles/rush.dir/scanner.cpp.s

# Object files for target rush
rush_OBJECTS = \
"CMakeFiles/rush.dir/cgen.cpp.o" \
"CMakeFiles/rush.dir/parser.tab.cpp.o" \
"CMakeFiles/rush.dir/scanner.cpp.o"

# External object files for target rush
rush_EXTERNAL_OBJECTS =

rush: CMakeFiles/rush.dir/cgen.cpp.o
rush: CMakeFiles/rush.dir/parser.tab.cpp.o
rush: CMakeFiles/rush.dir/scanner.cpp.o
rush: CMakeFiles/rush.dir/build.make
rush: /usr/lib/llvm-6.0/lib/libLLVMCore.a
rush: /usr/lib/llvm-6.0/lib/libLLVMSupport.a
rush: /usr/lib/llvm-6.0/lib/libLLVMBinaryFormat.a
rush: /usr/lib/llvm-6.0/lib/libLLVMSupport.a
rush: /usr/lib/llvm-6.0/lib/libLLVMDemangle.a
rush: CMakeFiles/rush.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/young/文档/编译工程/lab/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable rush"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rush.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rush.dir/build: rush

.PHONY : CMakeFiles/rush.dir/build

CMakeFiles/rush.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rush.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rush.dir/clean

CMakeFiles/rush.dir/depend:
	cd /home/young/文档/编译工程/lab/lab2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/young/文档/编译工程/lab/lab2 /home/young/文档/编译工程/lab/lab2 /home/young/文档/编译工程/lab/lab2/cmake-build-debug /home/young/文档/编译工程/lab/lab2/cmake-build-debug /home/young/文档/编译工程/lab/lab2/cmake-build-debug/CMakeFiles/rush.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rush.dir/depend

