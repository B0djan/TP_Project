# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_SOURCE_DIR = /home/andeo/GitHub/TP_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andeo/GitHub/TP_Project/build

# Include any dependencies generated for this target.
include project/CMakeFiles/HttpServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include project/CMakeFiles/HttpServer.dir/compiler_depend.make

# Include the progress variables for this target.
include project/CMakeFiles/HttpServer.dir/progress.make

# Include the compile flags for this target's objects.
include project/CMakeFiles/HttpServer.dir/flags.make

project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileInputStream.cpp.o: project/CMakeFiles/HttpServer.dir/flags.make
project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileInputStream.cpp.o: ../project/base_architecture/src/AsyncFileInputStream.cpp
project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileInputStream.cpp.o: project/CMakeFiles/HttpServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileInputStream.cpp.o"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileInputStream.cpp.o -MF CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileInputStream.cpp.o.d -o CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileInputStream.cpp.o -c /home/andeo/GitHub/TP_Project/project/base_architecture/src/AsyncFileInputStream.cpp

project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileInputStream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileInputStream.cpp.i"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/base_architecture/src/AsyncFileInputStream.cpp > CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileInputStream.cpp.i

project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileInputStream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileInputStream.cpp.s"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/base_architecture/src/AsyncFileInputStream.cpp -o CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileInputStream.cpp.s

project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileOutputStream.cpp.o: project/CMakeFiles/HttpServer.dir/flags.make
project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileOutputStream.cpp.o: ../project/base_architecture/src/AsyncFileOutputStream.cpp
project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileOutputStream.cpp.o: project/CMakeFiles/HttpServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileOutputStream.cpp.o"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileOutputStream.cpp.o -MF CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileOutputStream.cpp.o.d -o CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileOutputStream.cpp.o -c /home/andeo/GitHub/TP_Project/project/base_architecture/src/AsyncFileOutputStream.cpp

project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileOutputStream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileOutputStream.cpp.i"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/base_architecture/src/AsyncFileOutputStream.cpp > CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileOutputStream.cpp.i

project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileOutputStream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileOutputStream.cpp.s"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/base_architecture/src/AsyncFileOutputStream.cpp -o CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileOutputStream.cpp.s

project/CMakeFiles/HttpServer.dir/base_architecture/src/SelectBasedEventLoop.cpp.o: project/CMakeFiles/HttpServer.dir/flags.make
project/CMakeFiles/HttpServer.dir/base_architecture/src/SelectBasedEventLoop.cpp.o: ../project/base_architecture/src/SelectBasedEventLoop.cpp
project/CMakeFiles/HttpServer.dir/base_architecture/src/SelectBasedEventLoop.cpp.o: project/CMakeFiles/HttpServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object project/CMakeFiles/HttpServer.dir/base_architecture/src/SelectBasedEventLoop.cpp.o"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project/CMakeFiles/HttpServer.dir/base_architecture/src/SelectBasedEventLoop.cpp.o -MF CMakeFiles/HttpServer.dir/base_architecture/src/SelectBasedEventLoop.cpp.o.d -o CMakeFiles/HttpServer.dir/base_architecture/src/SelectBasedEventLoop.cpp.o -c /home/andeo/GitHub/TP_Project/project/base_architecture/src/SelectBasedEventLoop.cpp

project/CMakeFiles/HttpServer.dir/base_architecture/src/SelectBasedEventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HttpServer.dir/base_architecture/src/SelectBasedEventLoop.cpp.i"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/base_architecture/src/SelectBasedEventLoop.cpp > CMakeFiles/HttpServer.dir/base_architecture/src/SelectBasedEventLoop.cpp.i

project/CMakeFiles/HttpServer.dir/base_architecture/src/SelectBasedEventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HttpServer.dir/base_architecture/src/SelectBasedEventLoop.cpp.s"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/base_architecture/src/SelectBasedEventLoop.cpp -o CMakeFiles/HttpServer.dir/base_architecture/src/SelectBasedEventLoop.cpp.s

project/CMakeFiles/HttpServer.dir/base_architecture/src/ListeningNetworkSocket.cpp.o: project/CMakeFiles/HttpServer.dir/flags.make
project/CMakeFiles/HttpServer.dir/base_architecture/src/ListeningNetworkSocket.cpp.o: ../project/base_architecture/src/ListeningNetworkSocket.cpp
project/CMakeFiles/HttpServer.dir/base_architecture/src/ListeningNetworkSocket.cpp.o: project/CMakeFiles/HttpServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object project/CMakeFiles/HttpServer.dir/base_architecture/src/ListeningNetworkSocket.cpp.o"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project/CMakeFiles/HttpServer.dir/base_architecture/src/ListeningNetworkSocket.cpp.o -MF CMakeFiles/HttpServer.dir/base_architecture/src/ListeningNetworkSocket.cpp.o.d -o CMakeFiles/HttpServer.dir/base_architecture/src/ListeningNetworkSocket.cpp.o -c /home/andeo/GitHub/TP_Project/project/base_architecture/src/ListeningNetworkSocket.cpp

project/CMakeFiles/HttpServer.dir/base_architecture/src/ListeningNetworkSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HttpServer.dir/base_architecture/src/ListeningNetworkSocket.cpp.i"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/base_architecture/src/ListeningNetworkSocket.cpp > CMakeFiles/HttpServer.dir/base_architecture/src/ListeningNetworkSocket.cpp.i

project/CMakeFiles/HttpServer.dir/base_architecture/src/ListeningNetworkSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HttpServer.dir/base_architecture/src/ListeningNetworkSocket.cpp.s"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/base_architecture/src/ListeningNetworkSocket.cpp -o CMakeFiles/HttpServer.dir/base_architecture/src/ListeningNetworkSocket.cpp.s

project/CMakeFiles/HttpServer.dir/base_architecture/src/HttpClientAcceptor.cpp.o: project/CMakeFiles/HttpServer.dir/flags.make
project/CMakeFiles/HttpServer.dir/base_architecture/src/HttpClientAcceptor.cpp.o: ../project/base_architecture/src/HttpClientAcceptor.cpp
project/CMakeFiles/HttpServer.dir/base_architecture/src/HttpClientAcceptor.cpp.o: project/CMakeFiles/HttpServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object project/CMakeFiles/HttpServer.dir/base_architecture/src/HttpClientAcceptor.cpp.o"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project/CMakeFiles/HttpServer.dir/base_architecture/src/HttpClientAcceptor.cpp.o -MF CMakeFiles/HttpServer.dir/base_architecture/src/HttpClientAcceptor.cpp.o.d -o CMakeFiles/HttpServer.dir/base_architecture/src/HttpClientAcceptor.cpp.o -c /home/andeo/GitHub/TP_Project/project/base_architecture/src/HttpClientAcceptor.cpp

project/CMakeFiles/HttpServer.dir/base_architecture/src/HttpClientAcceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HttpServer.dir/base_architecture/src/HttpClientAcceptor.cpp.i"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/base_architecture/src/HttpClientAcceptor.cpp > CMakeFiles/HttpServer.dir/base_architecture/src/HttpClientAcceptor.cpp.i

project/CMakeFiles/HttpServer.dir/base_architecture/src/HttpClientAcceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HttpServer.dir/base_architecture/src/HttpClientAcceptor.cpp.s"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/base_architecture/src/HttpClientAcceptor.cpp -o CMakeFiles/HttpServer.dir/base_architecture/src/HttpClientAcceptor.cpp.s

project/CMakeFiles/HttpServer.dir/base_architecture/src/FileImpl.cpp.o: project/CMakeFiles/HttpServer.dir/flags.make
project/CMakeFiles/HttpServer.dir/base_architecture/src/FileImpl.cpp.o: ../project/base_architecture/src/FileImpl.cpp
project/CMakeFiles/HttpServer.dir/base_architecture/src/FileImpl.cpp.o: project/CMakeFiles/HttpServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object project/CMakeFiles/HttpServer.dir/base_architecture/src/FileImpl.cpp.o"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project/CMakeFiles/HttpServer.dir/base_architecture/src/FileImpl.cpp.o -MF CMakeFiles/HttpServer.dir/base_architecture/src/FileImpl.cpp.o.d -o CMakeFiles/HttpServer.dir/base_architecture/src/FileImpl.cpp.o -c /home/andeo/GitHub/TP_Project/project/base_architecture/src/FileImpl.cpp

project/CMakeFiles/HttpServer.dir/base_architecture/src/FileImpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HttpServer.dir/base_architecture/src/FileImpl.cpp.i"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/base_architecture/src/FileImpl.cpp > CMakeFiles/HttpServer.dir/base_architecture/src/FileImpl.cpp.i

project/CMakeFiles/HttpServer.dir/base_architecture/src/FileImpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HttpServer.dir/base_architecture/src/FileImpl.cpp.s"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/base_architecture/src/FileImpl.cpp -o CMakeFiles/HttpServer.dir/base_architecture/src/FileImpl.cpp.s

project/CMakeFiles/HttpServer.dir/base_architecture/src/main.cpp.o: project/CMakeFiles/HttpServer.dir/flags.make
project/CMakeFiles/HttpServer.dir/base_architecture/src/main.cpp.o: ../project/base_architecture/src/main.cpp
project/CMakeFiles/HttpServer.dir/base_architecture/src/main.cpp.o: project/CMakeFiles/HttpServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object project/CMakeFiles/HttpServer.dir/base_architecture/src/main.cpp.o"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project/CMakeFiles/HttpServer.dir/base_architecture/src/main.cpp.o -MF CMakeFiles/HttpServer.dir/base_architecture/src/main.cpp.o.d -o CMakeFiles/HttpServer.dir/base_architecture/src/main.cpp.o -c /home/andeo/GitHub/TP_Project/project/base_architecture/src/main.cpp

project/CMakeFiles/HttpServer.dir/base_architecture/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HttpServer.dir/base_architecture/src/main.cpp.i"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/base_architecture/src/main.cpp > CMakeFiles/HttpServer.dir/base_architecture/src/main.cpp.i

project/CMakeFiles/HttpServer.dir/base_architecture/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HttpServer.dir/base_architecture/src/main.cpp.s"
	cd /home/andeo/GitHub/TP_Project/build/project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/base_architecture/src/main.cpp -o CMakeFiles/HttpServer.dir/base_architecture/src/main.cpp.s

# Object files for target HttpServer
HttpServer_OBJECTS = \
"CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileInputStream.cpp.o" \
"CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileOutputStream.cpp.o" \
"CMakeFiles/HttpServer.dir/base_architecture/src/SelectBasedEventLoop.cpp.o" \
"CMakeFiles/HttpServer.dir/base_architecture/src/ListeningNetworkSocket.cpp.o" \
"CMakeFiles/HttpServer.dir/base_architecture/src/HttpClientAcceptor.cpp.o" \
"CMakeFiles/HttpServer.dir/base_architecture/src/FileImpl.cpp.o" \
"CMakeFiles/HttpServer.dir/base_architecture/src/main.cpp.o"

# External object files for target HttpServer
HttpServer_EXTERNAL_OBJECTS =

project/HttpServer: project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileInputStream.cpp.o
project/HttpServer: project/CMakeFiles/HttpServer.dir/base_architecture/src/AsyncFileOutputStream.cpp.o
project/HttpServer: project/CMakeFiles/HttpServer.dir/base_architecture/src/SelectBasedEventLoop.cpp.o
project/HttpServer: project/CMakeFiles/HttpServer.dir/base_architecture/src/ListeningNetworkSocket.cpp.o
project/HttpServer: project/CMakeFiles/HttpServer.dir/base_architecture/src/HttpClientAcceptor.cpp.o
project/HttpServer: project/CMakeFiles/HttpServer.dir/base_architecture/src/FileImpl.cpp.o
project/HttpServer: project/CMakeFiles/HttpServer.dir/base_architecture/src/main.cpp.o
project/HttpServer: project/CMakeFiles/HttpServer.dir/build.make
project/HttpServer: project/CMakeFiles/HttpServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andeo/GitHub/TP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable HttpServer"
	cd /home/andeo/GitHub/TP_Project/build/project && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HttpServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
project/CMakeFiles/HttpServer.dir/build: project/HttpServer
.PHONY : project/CMakeFiles/HttpServer.dir/build

project/CMakeFiles/HttpServer.dir/clean:
	cd /home/andeo/GitHub/TP_Project/build/project && $(CMAKE_COMMAND) -P CMakeFiles/HttpServer.dir/cmake_clean.cmake
.PHONY : project/CMakeFiles/HttpServer.dir/clean

project/CMakeFiles/HttpServer.dir/depend:
	cd /home/andeo/GitHub/TP_Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andeo/GitHub/TP_Project /home/andeo/GitHub/TP_Project/project /home/andeo/GitHub/TP_Project/build /home/andeo/GitHub/TP_Project/build/project /home/andeo/GitHub/TP_Project/build/project/CMakeFiles/HttpServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : project/CMakeFiles/HttpServer.dir/depend
