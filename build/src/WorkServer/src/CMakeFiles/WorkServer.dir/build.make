# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/testuser/cmake/cmake/bin/cmake

# The command to remove a file.
RM = /home/testuser/cmake/cmake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/app_user/sole/SoleApp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/app_user/sole/SoleApp/build

# Include any dependencies generated for this target.
include src/WorkServer/src/CMakeFiles/WorkServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/WorkServer/src/CMakeFiles/WorkServer.dir/compiler_depend.make

# Include the progress variables for this target.
include src/WorkServer/src/CMakeFiles/WorkServer.dir/progress.make

# Include the compile flags for this target's objects.
include src/WorkServer/src/CMakeFiles/WorkServer.dir/flags.make

src/WorkServer/src/CMakeFiles/WorkServer.dir/Schedule.cpp.o: src/WorkServer/src/CMakeFiles/WorkServer.dir/flags.make
src/WorkServer/src/CMakeFiles/WorkServer.dir/Schedule.cpp.o: ../src/WorkServer/src/Schedule.cpp
src/WorkServer/src/CMakeFiles/WorkServer.dir/Schedule.cpp.o: src/WorkServer/src/CMakeFiles/WorkServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/app_user/sole/SoleApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/WorkServer/src/CMakeFiles/WorkServer.dir/Schedule.cpp.o"
	cd /home/app_user/sole/SoleApp/build/src/WorkServer/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/WorkServer/src/CMakeFiles/WorkServer.dir/Schedule.cpp.o -MF CMakeFiles/WorkServer.dir/Schedule.cpp.o.d -o CMakeFiles/WorkServer.dir/Schedule.cpp.o -c /home/app_user/sole/SoleApp/src/WorkServer/src/Schedule.cpp

src/WorkServer/src/CMakeFiles/WorkServer.dir/Schedule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WorkServer.dir/Schedule.cpp.i"
	cd /home/app_user/sole/SoleApp/build/src/WorkServer/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/app_user/sole/SoleApp/src/WorkServer/src/Schedule.cpp > CMakeFiles/WorkServer.dir/Schedule.cpp.i

src/WorkServer/src/CMakeFiles/WorkServer.dir/Schedule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WorkServer.dir/Schedule.cpp.s"
	cd /home/app_user/sole/SoleApp/build/src/WorkServer/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/app_user/sole/SoleApp/src/WorkServer/src/Schedule.cpp -o CMakeFiles/WorkServer.dir/Schedule.cpp.s

src/WorkServer/src/CMakeFiles/WorkServer.dir/ServiceImp.cpp.o: src/WorkServer/src/CMakeFiles/WorkServer.dir/flags.make
src/WorkServer/src/CMakeFiles/WorkServer.dir/ServiceImp.cpp.o: ../src/WorkServer/src/ServiceImp.cpp
src/WorkServer/src/CMakeFiles/WorkServer.dir/ServiceImp.cpp.o: src/WorkServer/src/CMakeFiles/WorkServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/app_user/sole/SoleApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/WorkServer/src/CMakeFiles/WorkServer.dir/ServiceImp.cpp.o"
	cd /home/app_user/sole/SoleApp/build/src/WorkServer/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/WorkServer/src/CMakeFiles/WorkServer.dir/ServiceImp.cpp.o -MF CMakeFiles/WorkServer.dir/ServiceImp.cpp.o.d -o CMakeFiles/WorkServer.dir/ServiceImp.cpp.o -c /home/app_user/sole/SoleApp/src/WorkServer/src/ServiceImp.cpp

src/WorkServer/src/CMakeFiles/WorkServer.dir/ServiceImp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WorkServer.dir/ServiceImp.cpp.i"
	cd /home/app_user/sole/SoleApp/build/src/WorkServer/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/app_user/sole/SoleApp/src/WorkServer/src/ServiceImp.cpp > CMakeFiles/WorkServer.dir/ServiceImp.cpp.i

src/WorkServer/src/CMakeFiles/WorkServer.dir/ServiceImp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WorkServer.dir/ServiceImp.cpp.s"
	cd /home/app_user/sole/SoleApp/build/src/WorkServer/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/app_user/sole/SoleApp/src/WorkServer/src/ServiceImp.cpp -o CMakeFiles/WorkServer.dir/ServiceImp.cpp.s

src/WorkServer/src/CMakeFiles/WorkServer.dir/WorkServer.cpp.o: src/WorkServer/src/CMakeFiles/WorkServer.dir/flags.make
src/WorkServer/src/CMakeFiles/WorkServer.dir/WorkServer.cpp.o: ../src/WorkServer/src/WorkServer.cpp
src/WorkServer/src/CMakeFiles/WorkServer.dir/WorkServer.cpp.o: src/WorkServer/src/CMakeFiles/WorkServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/app_user/sole/SoleApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/WorkServer/src/CMakeFiles/WorkServer.dir/WorkServer.cpp.o"
	cd /home/app_user/sole/SoleApp/build/src/WorkServer/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/WorkServer/src/CMakeFiles/WorkServer.dir/WorkServer.cpp.o -MF CMakeFiles/WorkServer.dir/WorkServer.cpp.o.d -o CMakeFiles/WorkServer.dir/WorkServer.cpp.o -c /home/app_user/sole/SoleApp/src/WorkServer/src/WorkServer.cpp

src/WorkServer/src/CMakeFiles/WorkServer.dir/WorkServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WorkServer.dir/WorkServer.cpp.i"
	cd /home/app_user/sole/SoleApp/build/src/WorkServer/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/app_user/sole/SoleApp/src/WorkServer/src/WorkServer.cpp > CMakeFiles/WorkServer.dir/WorkServer.cpp.i

src/WorkServer/src/CMakeFiles/WorkServer.dir/WorkServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WorkServer.dir/WorkServer.cpp.s"
	cd /home/app_user/sole/SoleApp/build/src/WorkServer/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/app_user/sole/SoleApp/src/WorkServer/src/WorkServer.cpp -o CMakeFiles/WorkServer.dir/WorkServer.cpp.s

# Object files for target WorkServer
WorkServer_OBJECTS = \
"CMakeFiles/WorkServer.dir/Schedule.cpp.o" \
"CMakeFiles/WorkServer.dir/ServiceImp.cpp.o" \
"CMakeFiles/WorkServer.dir/WorkServer.cpp.o"

# External object files for target WorkServer
WorkServer_EXTERNAL_OBJECTS =

bin/WorkServer: src/WorkServer/src/CMakeFiles/WorkServer.dir/Schedule.cpp.o
bin/WorkServer: src/WorkServer/src/CMakeFiles/WorkServer.dir/ServiceImp.cpp.o
bin/WorkServer: src/WorkServer/src/CMakeFiles/WorkServer.dir/WorkServer.cpp.o
bin/WorkServer: src/WorkServer/src/CMakeFiles/WorkServer.dir/build.make
bin/WorkServer: /usr/local/tars/cpp/lib/libtarsservant.a
bin/WorkServer: /usr/local/tars/cpp/lib/libtarsutil.a
bin/WorkServer: lib/libsoleengine.a
bin/WorkServer: lib/libsoleutils.a
bin/WorkServer: lib/libsoleparse.a
bin/WorkServer: src/WorkServer/src/CMakeFiles/WorkServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/app_user/sole/SoleApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../../bin/WorkServer"
	cd /home/app_user/sole/SoleApp/build/src/WorkServer/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WorkServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/WorkServer/src/CMakeFiles/WorkServer.dir/build: bin/WorkServer
.PHONY : src/WorkServer/src/CMakeFiles/WorkServer.dir/build

src/WorkServer/src/CMakeFiles/WorkServer.dir/clean:
	cd /home/app_user/sole/SoleApp/build/src/WorkServer/src && $(CMAKE_COMMAND) -P CMakeFiles/WorkServer.dir/cmake_clean.cmake
.PHONY : src/WorkServer/src/CMakeFiles/WorkServer.dir/clean

src/WorkServer/src/CMakeFiles/WorkServer.dir/depend:
	cd /home/app_user/sole/SoleApp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/app_user/sole/SoleApp /home/app_user/sole/SoleApp/src/WorkServer/src /home/app_user/sole/SoleApp/build /home/app_user/sole/SoleApp/build/src/WorkServer/src /home/app_user/sole/SoleApp/build/src/WorkServer/src/CMakeFiles/WorkServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/WorkServer/src/CMakeFiles/WorkServer.dir/depend

