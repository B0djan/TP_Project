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
CMAKE_COMMAND = /home/andeo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/andeo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andeo/GitHub/TP_Project/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andeo/GitHub/TP_Project/project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project.dir/flags.make

CMakeFiles/Project.dir/base_architecture/src/AsyncFileInputStream.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/base_architecture/src/AsyncFileInputStream.o: ../base_architecture/src/AsyncFileInputStream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project.dir/base_architecture/src/AsyncFileInputStream.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/base_architecture/src/AsyncFileInputStream.o -c /home/andeo/GitHub/TP_Project/project/base_architecture/src/AsyncFileInputStream.cpp

CMakeFiles/Project.dir/base_architecture/src/AsyncFileInputStream.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/base_architecture/src/AsyncFileInputStream.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/base_architecture/src/AsyncFileInputStream.cpp > CMakeFiles/Project.dir/base_architecture/src/AsyncFileInputStream.i

CMakeFiles/Project.dir/base_architecture/src/AsyncFileInputStream.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/base_architecture/src/AsyncFileInputStream.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/base_architecture/src/AsyncFileInputStream.cpp -o CMakeFiles/Project.dir/base_architecture/src/AsyncFileInputStream.s

CMakeFiles/Project.dir/base_architecture/src/AsyncFileOutputStream.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/base_architecture/src/AsyncFileOutputStream.o: ../base_architecture/src/AsyncFileOutputStream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project.dir/base_architecture/src/AsyncFileOutputStream.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/base_architecture/src/AsyncFileOutputStream.o -c /home/andeo/GitHub/TP_Project/project/base_architecture/src/AsyncFileOutputStream.cpp

CMakeFiles/Project.dir/base_architecture/src/AsyncFileOutputStream.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/base_architecture/src/AsyncFileOutputStream.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/base_architecture/src/AsyncFileOutputStream.cpp > CMakeFiles/Project.dir/base_architecture/src/AsyncFileOutputStream.i

CMakeFiles/Project.dir/base_architecture/src/AsyncFileOutputStream.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/base_architecture/src/AsyncFileOutputStream.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/base_architecture/src/AsyncFileOutputStream.cpp -o CMakeFiles/Project.dir/base_architecture/src/AsyncFileOutputStream.s

CMakeFiles/Project.dir/base_architecture/src/SelectBasedEventLoop.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/base_architecture/src/SelectBasedEventLoop.o: ../base_architecture/src/SelectBasedEventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Project.dir/base_architecture/src/SelectBasedEventLoop.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/base_architecture/src/SelectBasedEventLoop.o -c /home/andeo/GitHub/TP_Project/project/base_architecture/src/SelectBasedEventLoop.cpp

CMakeFiles/Project.dir/base_architecture/src/SelectBasedEventLoop.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/base_architecture/src/SelectBasedEventLoop.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/base_architecture/src/SelectBasedEventLoop.cpp > CMakeFiles/Project.dir/base_architecture/src/SelectBasedEventLoop.i

CMakeFiles/Project.dir/base_architecture/src/SelectBasedEventLoop.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/base_architecture/src/SelectBasedEventLoop.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/base_architecture/src/SelectBasedEventLoop.cpp -o CMakeFiles/Project.dir/base_architecture/src/SelectBasedEventLoop.s

CMakeFiles/Project.dir/base_architecture/src/ListeningNetworkSocket.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/base_architecture/src/ListeningNetworkSocket.o: ../base_architecture/src/ListeningNetworkSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Project.dir/base_architecture/src/ListeningNetworkSocket.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/base_architecture/src/ListeningNetworkSocket.o -c /home/andeo/GitHub/TP_Project/project/base_architecture/src/ListeningNetworkSocket.cpp

CMakeFiles/Project.dir/base_architecture/src/ListeningNetworkSocket.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/base_architecture/src/ListeningNetworkSocket.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/base_architecture/src/ListeningNetworkSocket.cpp > CMakeFiles/Project.dir/base_architecture/src/ListeningNetworkSocket.i

CMakeFiles/Project.dir/base_architecture/src/ListeningNetworkSocket.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/base_architecture/src/ListeningNetworkSocket.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/base_architecture/src/ListeningNetworkSocket.cpp -o CMakeFiles/Project.dir/base_architecture/src/ListeningNetworkSocket.s

CMakeFiles/Project.dir/base_architecture/src/HttpClientAcceptor.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/base_architecture/src/HttpClientAcceptor.o: ../base_architecture/src/HttpClientAcceptor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Project.dir/base_architecture/src/HttpClientAcceptor.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/base_architecture/src/HttpClientAcceptor.o -c /home/andeo/GitHub/TP_Project/project/base_architecture/src/HttpClientAcceptor.cpp

CMakeFiles/Project.dir/base_architecture/src/HttpClientAcceptor.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/base_architecture/src/HttpClientAcceptor.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/base_architecture/src/HttpClientAcceptor.cpp > CMakeFiles/Project.dir/base_architecture/src/HttpClientAcceptor.i

CMakeFiles/Project.dir/base_architecture/src/HttpClientAcceptor.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/base_architecture/src/HttpClientAcceptor.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/base_architecture/src/HttpClientAcceptor.cpp -o CMakeFiles/Project.dir/base_architecture/src/HttpClientAcceptor.s

CMakeFiles/Project.dir/base_architecture/src/FileImpl.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/base_architecture/src/FileImpl.o: ../base_architecture/src/FileImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Project.dir/base_architecture/src/FileImpl.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/base_architecture/src/FileImpl.o -c /home/andeo/GitHub/TP_Project/project/base_architecture/src/FileImpl.cpp

CMakeFiles/Project.dir/base_architecture/src/FileImpl.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/base_architecture/src/FileImpl.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/base_architecture/src/FileImpl.cpp > CMakeFiles/Project.dir/base_architecture/src/FileImpl.i

CMakeFiles/Project.dir/base_architecture/src/FileImpl.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/base_architecture/src/FileImpl.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/base_architecture/src/FileImpl.cpp -o CMakeFiles/Project.dir/base_architecture/src/FileImpl.s

CMakeFiles/Project.dir/base_architecture/src/main.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/base_architecture/src/main.o: ../base_architecture/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Project.dir/base_architecture/src/main.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/base_architecture/src/main.o -c /home/andeo/GitHub/TP_Project/project/base_architecture/src/main.cpp

CMakeFiles/Project.dir/base_architecture/src/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/base_architecture/src/main.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/base_architecture/src/main.cpp > CMakeFiles/Project.dir/base_architecture/src/main.i

CMakeFiles/Project.dir/base_architecture/src/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/base_architecture/src/main.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/base_architecture/src/main.cpp -o CMakeFiles/Project.dir/base_architecture/src/main.s

CMakeFiles/Project.dir/processing_class/src/ContactsImpl.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/processing_class/src/ContactsImpl.o: ../processing_class/src/ContactsImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Project.dir/processing_class/src/ContactsImpl.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/processing_class/src/ContactsImpl.o -c /home/andeo/GitHub/TP_Project/project/processing_class/src/ContactsImpl.cpp

CMakeFiles/Project.dir/processing_class/src/ContactsImpl.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/processing_class/src/ContactsImpl.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/processing_class/src/ContactsImpl.cpp > CMakeFiles/Project.dir/processing_class/src/ContactsImpl.i

CMakeFiles/Project.dir/processing_class/src/ContactsImpl.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/processing_class/src/ContactsImpl.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/processing_class/src/ContactsImpl.cpp -o CMakeFiles/Project.dir/processing_class/src/ContactsImpl.s

CMakeFiles/Project.dir/processing_class/src/EventImpl.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/processing_class/src/EventImpl.o: ../processing_class/src/EventImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Project.dir/processing_class/src/EventImpl.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/processing_class/src/EventImpl.o -c /home/andeo/GitHub/TP_Project/project/processing_class/src/EventImpl.cpp

CMakeFiles/Project.dir/processing_class/src/EventImpl.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/processing_class/src/EventImpl.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/processing_class/src/EventImpl.cpp > CMakeFiles/Project.dir/processing_class/src/EventImpl.i

CMakeFiles/Project.dir/processing_class/src/EventImpl.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/processing_class/src/EventImpl.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/processing_class/src/EventImpl.cpp -o CMakeFiles/Project.dir/processing_class/src/EventImpl.s

CMakeFiles/Project.dir/processing_class/src/GroupImpl.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/processing_class/src/GroupImpl.o: ../processing_class/src/GroupImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Project.dir/processing_class/src/GroupImpl.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/processing_class/src/GroupImpl.o -c /home/andeo/GitHub/TP_Project/project/processing_class/src/GroupImpl.cpp

CMakeFiles/Project.dir/processing_class/src/GroupImpl.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/processing_class/src/GroupImpl.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/processing_class/src/GroupImpl.cpp > CMakeFiles/Project.dir/processing_class/src/GroupImpl.i

CMakeFiles/Project.dir/processing_class/src/GroupImpl.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/processing_class/src/GroupImpl.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/processing_class/src/GroupImpl.cpp -o CMakeFiles/Project.dir/processing_class/src/GroupImpl.s

CMakeFiles/Project.dir/processing_class/src/RegistrAuthImpl.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/processing_class/src/RegistrAuthImpl.o: ../processing_class/src/RegistrAuthImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Project.dir/processing_class/src/RegistrAuthImpl.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/processing_class/src/RegistrAuthImpl.o -c /home/andeo/GitHub/TP_Project/project/processing_class/src/RegistrAuthImpl.cpp

CMakeFiles/Project.dir/processing_class/src/RegistrAuthImpl.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/processing_class/src/RegistrAuthImpl.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/processing_class/src/RegistrAuthImpl.cpp > CMakeFiles/Project.dir/processing_class/src/RegistrAuthImpl.i

CMakeFiles/Project.dir/processing_class/src/RegistrAuthImpl.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/processing_class/src/RegistrAuthImpl.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/processing_class/src/RegistrAuthImpl.cpp -o CMakeFiles/Project.dir/processing_class/src/RegistrAuthImpl.s

CMakeFiles/Project.dir/processing_class/src/SynchroClientImpl.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/processing_class/src/SynchroClientImpl.o: ../processing_class/src/SynchroClientImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Project.dir/processing_class/src/SynchroClientImpl.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/processing_class/src/SynchroClientImpl.o -c /home/andeo/GitHub/TP_Project/project/processing_class/src/SynchroClientImpl.cpp

CMakeFiles/Project.dir/processing_class/src/SynchroClientImpl.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/processing_class/src/SynchroClientImpl.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/processing_class/src/SynchroClientImpl.cpp > CMakeFiles/Project.dir/processing_class/src/SynchroClientImpl.i

CMakeFiles/Project.dir/processing_class/src/SynchroClientImpl.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/processing_class/src/SynchroClientImpl.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/processing_class/src/SynchroClientImpl.cpp -o CMakeFiles/Project.dir/processing_class/src/SynchroClientImpl.s

CMakeFiles/Project.dir/processing_class/src/WriteAddressDataImpl.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/processing_class/src/WriteAddressDataImpl.o: ../processing_class/src/WriteAddressDataImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Project.dir/processing_class/src/WriteAddressDataImpl.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/processing_class/src/WriteAddressDataImpl.o -c /home/andeo/GitHub/TP_Project/project/processing_class/src/WriteAddressDataImpl.cpp

CMakeFiles/Project.dir/processing_class/src/WriteAddressDataImpl.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/processing_class/src/WriteAddressDataImpl.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/processing_class/src/WriteAddressDataImpl.cpp > CMakeFiles/Project.dir/processing_class/src/WriteAddressDataImpl.i

CMakeFiles/Project.dir/processing_class/src/WriteAddressDataImpl.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/processing_class/src/WriteAddressDataImpl.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/processing_class/src/WriteAddressDataImpl.cpp -o CMakeFiles/Project.dir/processing_class/src/WriteAddressDataImpl.s

CMakeFiles/Project.dir/processing_class/src/WritePersonalDataImpl.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/processing_class/src/WritePersonalDataImpl.o: ../processing_class/src/WritePersonalDataImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Project.dir/processing_class/src/WritePersonalDataImpl.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/processing_class/src/WritePersonalDataImpl.o -c /home/andeo/GitHub/TP_Project/project/processing_class/src/WritePersonalDataImpl.cpp

CMakeFiles/Project.dir/processing_class/src/WritePersonalDataImpl.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/processing_class/src/WritePersonalDataImpl.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/processing_class/src/WritePersonalDataImpl.cpp > CMakeFiles/Project.dir/processing_class/src/WritePersonalDataImpl.i

CMakeFiles/Project.dir/processing_class/src/WritePersonalDataImpl.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/processing_class/src/WritePersonalDataImpl.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/processing_class/src/WritePersonalDataImpl.cpp -o CMakeFiles/Project.dir/processing_class/src/WritePersonalDataImpl.s

CMakeFiles/Project.dir/route/src/RouteImpl.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/route/src/RouteImpl.o: ../route/src/RouteImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Project.dir/route/src/RouteImpl.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/route/src/RouteImpl.o -c /home/andeo/GitHub/TP_Project/project/route/src/RouteImpl.cpp

CMakeFiles/Project.dir/route/src/RouteImpl.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/route/src/RouteImpl.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/route/src/RouteImpl.cpp > CMakeFiles/Project.dir/route/src/RouteImpl.i

CMakeFiles/Project.dir/route/src/RouteImpl.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/route/src/RouteImpl.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/route/src/RouteImpl.cpp -o CMakeFiles/Project.dir/route/src/RouteImpl.s

CMakeFiles/Project.dir/parser/src/JSON.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/parser/src/JSON.o: ../parser/src/JSON.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Project.dir/parser/src/JSON.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/parser/src/JSON.o -c /home/andeo/GitHub/TP_Project/project/parser/src/JSON.cpp

CMakeFiles/Project.dir/parser/src/JSON.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/parser/src/JSON.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andeo/GitHub/TP_Project/project/parser/src/JSON.cpp > CMakeFiles/Project.dir/parser/src/JSON.i

CMakeFiles/Project.dir/parser/src/JSON.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/parser/src/JSON.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andeo/GitHub/TP_Project/project/parser/src/JSON.cpp -o CMakeFiles/Project.dir/parser/src/JSON.s

# Object files for target Project
Project_OBJECTS = \
"CMakeFiles/Project.dir/base_architecture/src/AsyncFileInputStream.o" \
"CMakeFiles/Project.dir/base_architecture/src/AsyncFileOutputStream.o" \
"CMakeFiles/Project.dir/base_architecture/src/SelectBasedEventLoop.o" \
"CMakeFiles/Project.dir/base_architecture/src/ListeningNetworkSocket.o" \
"CMakeFiles/Project.dir/base_architecture/src/HttpClientAcceptor.o" \
"CMakeFiles/Project.dir/base_architecture/src/FileImpl.o" \
"CMakeFiles/Project.dir/base_architecture/src/main.o" \
"CMakeFiles/Project.dir/processing_class/src/ContactsImpl.o" \
"CMakeFiles/Project.dir/processing_class/src/EventImpl.o" \
"CMakeFiles/Project.dir/processing_class/src/GroupImpl.o" \
"CMakeFiles/Project.dir/processing_class/src/RegistrAuthImpl.o" \
"CMakeFiles/Project.dir/processing_class/src/SynchroClientImpl.o" \
"CMakeFiles/Project.dir/processing_class/src/WriteAddressDataImpl.o" \
"CMakeFiles/Project.dir/processing_class/src/WritePersonalDataImpl.o" \
"CMakeFiles/Project.dir/route/src/RouteImpl.o" \
"CMakeFiles/Project.dir/parser/src/JSON.o"

# External object files for target Project
Project_EXTERNAL_OBJECTS =

Project: CMakeFiles/Project.dir/base_architecture/src/AsyncFileInputStream.o
Project: CMakeFiles/Project.dir/base_architecture/src/AsyncFileOutputStream.o
Project: CMakeFiles/Project.dir/base_architecture/src/SelectBasedEventLoop.o
Project: CMakeFiles/Project.dir/base_architecture/src/ListeningNetworkSocket.o
Project: CMakeFiles/Project.dir/base_architecture/src/HttpClientAcceptor.o
Project: CMakeFiles/Project.dir/base_architecture/src/FileImpl.o
Project: CMakeFiles/Project.dir/base_architecture/src/main.o
Project: CMakeFiles/Project.dir/processing_class/src/ContactsImpl.o
Project: CMakeFiles/Project.dir/processing_class/src/EventImpl.o
Project: CMakeFiles/Project.dir/processing_class/src/GroupImpl.o
Project: CMakeFiles/Project.dir/processing_class/src/RegistrAuthImpl.o
Project: CMakeFiles/Project.dir/processing_class/src/SynchroClientImpl.o
Project: CMakeFiles/Project.dir/processing_class/src/WriteAddressDataImpl.o
Project: CMakeFiles/Project.dir/processing_class/src/WritePersonalDataImpl.o
Project: CMakeFiles/Project.dir/route/src/RouteImpl.o
Project: CMakeFiles/Project.dir/parser/src/JSON.o
Project: CMakeFiles/Project.dir/build.make
Project: CMakeFiles/Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable Project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project.dir/build: Project
.PHONY : CMakeFiles/Project.dir/build

CMakeFiles/Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project.dir/clean

CMakeFiles/Project.dir/depend:
	cd /home/andeo/GitHub/TP_Project/project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andeo/GitHub/TP_Project/project /home/andeo/GitHub/TP_Project/project /home/andeo/GitHub/TP_Project/project/cmake-build-debug /home/andeo/GitHub/TP_Project/project/cmake-build-debug /home/andeo/GitHub/TP_Project/project/cmake-build-debug/CMakeFiles/Project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project.dir/depend
