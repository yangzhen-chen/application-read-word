# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chenyangzhen/CLionProjects/NF16_TP4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chenyangzhen/CLionProjects/NF16_TP4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NF16_TP4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NF16_TP4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NF16_TP4.dir/flags.make

CMakeFiles/NF16_TP4.dir/main.c.o: CMakeFiles/NF16_TP4.dir/flags.make
CMakeFiles/NF16_TP4.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chenyangzhen/CLionProjects/NF16_TP4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/NF16_TP4.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NF16_TP4.dir/main.c.o   -c /Users/chenyangzhen/CLionProjects/NF16_TP4/main.c

CMakeFiles/NF16_TP4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NF16_TP4.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/chenyangzhen/CLionProjects/NF16_TP4/main.c > CMakeFiles/NF16_TP4.dir/main.c.i

CMakeFiles/NF16_TP4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NF16_TP4.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/chenyangzhen/CLionProjects/NF16_TP4/main.c -o CMakeFiles/NF16_TP4.dir/main.c.s

CMakeFiles/NF16_TP4.dir/tp4.c.o: CMakeFiles/NF16_TP4.dir/flags.make
CMakeFiles/NF16_TP4.dir/tp4.c.o: ../tp4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chenyangzhen/CLionProjects/NF16_TP4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/NF16_TP4.dir/tp4.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NF16_TP4.dir/tp4.c.o   -c /Users/chenyangzhen/CLionProjects/NF16_TP4/tp4.c

CMakeFiles/NF16_TP4.dir/tp4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NF16_TP4.dir/tp4.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/chenyangzhen/CLionProjects/NF16_TP4/tp4.c > CMakeFiles/NF16_TP4.dir/tp4.c.i

CMakeFiles/NF16_TP4.dir/tp4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NF16_TP4.dir/tp4.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/chenyangzhen/CLionProjects/NF16_TP4/tp4.c -o CMakeFiles/NF16_TP4.dir/tp4.c.s

# Object files for target NF16_TP4
NF16_TP4_OBJECTS = \
"CMakeFiles/NF16_TP4.dir/main.c.o" \
"CMakeFiles/NF16_TP4.dir/tp4.c.o"

# External object files for target NF16_TP4
NF16_TP4_EXTERNAL_OBJECTS =

NF16_TP4: CMakeFiles/NF16_TP4.dir/main.c.o
NF16_TP4: CMakeFiles/NF16_TP4.dir/tp4.c.o
NF16_TP4: CMakeFiles/NF16_TP4.dir/build.make
NF16_TP4: CMakeFiles/NF16_TP4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chenyangzhen/CLionProjects/NF16_TP4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable NF16_TP4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NF16_TP4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NF16_TP4.dir/build: NF16_TP4

.PHONY : CMakeFiles/NF16_TP4.dir/build

CMakeFiles/NF16_TP4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NF16_TP4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NF16_TP4.dir/clean

CMakeFiles/NF16_TP4.dir/depend:
	cd /Users/chenyangzhen/CLionProjects/NF16_TP4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chenyangzhen/CLionProjects/NF16_TP4 /Users/chenyangzhen/CLionProjects/NF16_TP4 /Users/chenyangzhen/CLionProjects/NF16_TP4/cmake-build-debug /Users/chenyangzhen/CLionProjects/NF16_TP4/cmake-build-debug /Users/chenyangzhen/CLionProjects/NF16_TP4/cmake-build-debug/CMakeFiles/NF16_TP4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NF16_TP4.dir/depend

