# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrefmrocha/Projects/MIEIC_CAl_PROJ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrefmrocha/Projects/MIEIC_CAl_PROJ

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/andrefmrocha/Projects/MIEIC_CAl_PROJ/CMakeFiles /home/andrefmrocha/Projects/MIEIC_CAl_PROJ/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/andrefmrocha/Projects/MIEIC_CAl_PROJ/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named MIEIC_CAl_PROJ

# Build rule for target.
MIEIC_CAl_PROJ: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 MIEIC_CAl_PROJ
.PHONY : MIEIC_CAl_PROJ

# fast build rule for target.
MIEIC_CAl_PROJ/fast:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/build
.PHONY : MIEIC_CAl_PROJ/fast

Appointment.o: Appointment.cpp.o

.PHONY : Appointment.o

# target to build an object file
Appointment.cpp.o:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Appointment.cpp.o
.PHONY : Appointment.cpp.o

Appointment.i: Appointment.cpp.i

.PHONY : Appointment.i

# target to preprocess a source file
Appointment.cpp.i:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Appointment.cpp.i
.PHONY : Appointment.cpp.i

Appointment.s: Appointment.cpp.s

.PHONY : Appointment.s

# target to generate assembly for a file
Appointment.cpp.s:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Appointment.cpp.s
.PHONY : Appointment.cpp.s

Coordinates.o: Coordinates.cpp.o

.PHONY : Coordinates.o

# target to build an object file
Coordinates.cpp.o:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Coordinates.cpp.o
.PHONY : Coordinates.cpp.o

Coordinates.i: Coordinates.cpp.i

.PHONY : Coordinates.i

# target to preprocess a source file
Coordinates.cpp.i:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Coordinates.cpp.i
.PHONY : Coordinates.cpp.i

Coordinates.s: Coordinates.cpp.s

.PHONY : Coordinates.s

# target to generate assembly for a file
Coordinates.cpp.s:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Coordinates.cpp.s
.PHONY : Coordinates.cpp.s

Graph.o: Graph.cpp.o

.PHONY : Graph.o

# target to build an object file
Graph.cpp.o:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Graph.cpp.o
.PHONY : Graph.cpp.o

Graph.i: Graph.cpp.i

.PHONY : Graph.i

# target to preprocess a source file
Graph.cpp.i:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Graph.cpp.i
.PHONY : Graph.cpp.i

Graph.s: Graph.cpp.s

.PHONY : Graph.s

# target to generate assembly for a file
Graph.cpp.s:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Graph.cpp.s
.PHONY : Graph.cpp.s

GraphViewer/GraphicalInterface.o: GraphViewer/GraphicalInterface.cpp.o

.PHONY : GraphViewer/GraphicalInterface.o

# target to build an object file
GraphViewer/GraphicalInterface.cpp.o:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/GraphViewer/GraphicalInterface.cpp.o
.PHONY : GraphViewer/GraphicalInterface.cpp.o

GraphViewer/GraphicalInterface.i: GraphViewer/GraphicalInterface.cpp.i

.PHONY : GraphViewer/GraphicalInterface.i

# target to preprocess a source file
GraphViewer/GraphicalInterface.cpp.i:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/GraphViewer/GraphicalInterface.cpp.i
.PHONY : GraphViewer/GraphicalInterface.cpp.i

GraphViewer/GraphicalInterface.s: GraphViewer/GraphicalInterface.cpp.s

.PHONY : GraphViewer/GraphicalInterface.s

# target to generate assembly for a file
GraphViewer/GraphicalInterface.cpp.s:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/GraphViewer/GraphicalInterface.cpp.s
.PHONY : GraphViewer/GraphicalInterface.cpp.s

GraphViewer/connection.o: GraphViewer/connection.cpp.o

.PHONY : GraphViewer/connection.o

# target to build an object file
GraphViewer/connection.cpp.o:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/GraphViewer/connection.cpp.o
.PHONY : GraphViewer/connection.cpp.o

GraphViewer/connection.i: GraphViewer/connection.cpp.i

.PHONY : GraphViewer/connection.i

# target to preprocess a source file
GraphViewer/connection.cpp.i:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/GraphViewer/connection.cpp.i
.PHONY : GraphViewer/connection.cpp.i

GraphViewer/connection.s: GraphViewer/connection.cpp.s

.PHONY : GraphViewer/connection.s

# target to generate assembly for a file
GraphViewer/connection.cpp.s:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/GraphViewer/connection.cpp.s
.PHONY : GraphViewer/connection.cpp.s

GraphViewer/graphviewer.o: GraphViewer/graphviewer.cpp.o

.PHONY : GraphViewer/graphviewer.o

# target to build an object file
GraphViewer/graphviewer.cpp.o:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/GraphViewer/graphviewer.cpp.o
.PHONY : GraphViewer/graphviewer.cpp.o

GraphViewer/graphviewer.i: GraphViewer/graphviewer.cpp.i

.PHONY : GraphViewer/graphviewer.i

# target to preprocess a source file
GraphViewer/graphviewer.cpp.i:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/GraphViewer/graphviewer.cpp.i
.PHONY : GraphViewer/graphviewer.cpp.i

GraphViewer/graphviewer.s: GraphViewer/graphviewer.cpp.s

.PHONY : GraphViewer/graphviewer.s

# target to generate assembly for a file
GraphViewer/graphviewer.cpp.s:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/GraphViewer/graphviewer.cpp.s
.PHONY : GraphViewer/graphviewer.cpp.s

Heuristics.o: Heuristics.cpp.o

.PHONY : Heuristics.o

# target to build an object file
Heuristics.cpp.o:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Heuristics.cpp.o
.PHONY : Heuristics.cpp.o

Heuristics.i: Heuristics.cpp.i

.PHONY : Heuristics.i

# target to preprocess a source file
Heuristics.cpp.i:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Heuristics.cpp.i
.PHONY : Heuristics.cpp.i

Heuristics.s: Heuristics.cpp.s

.PHONY : Heuristics.s

# target to generate assembly for a file
Heuristics.cpp.s:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Heuristics.cpp.s
.PHONY : Heuristics.cpp.s

Schedule.o: Schedule.cpp.o

.PHONY : Schedule.o

# target to build an object file
Schedule.cpp.o:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Schedule.cpp.o
.PHONY : Schedule.cpp.o

Schedule.i: Schedule.cpp.i

.PHONY : Schedule.i

# target to preprocess a source file
Schedule.cpp.i:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Schedule.cpp.i
.PHONY : Schedule.cpp.i

Schedule.s: Schedule.cpp.s

.PHONY : Schedule.s

# target to generate assembly for a file
Schedule.cpp.s:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Schedule.cpp.s
.PHONY : Schedule.cpp.s

TestGraph.o: TestGraph.cpp.o

.PHONY : TestGraph.o

# target to build an object file
TestGraph.cpp.o:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/TestGraph.cpp.o
.PHONY : TestGraph.cpp.o

TestGraph.i: TestGraph.cpp.i

.PHONY : TestGraph.i

# target to preprocess a source file
TestGraph.cpp.i:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/TestGraph.cpp.i
.PHONY : TestGraph.cpp.i

TestGraph.s: TestGraph.cpp.s

.PHONY : TestGraph.s

# target to generate assembly for a file
TestGraph.cpp.s:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/TestGraph.cpp.s
.PHONY : TestGraph.cpp.s

TripMate.o: TripMate.cpp.o

.PHONY : TripMate.o

# target to build an object file
TripMate.cpp.o:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/TripMate.cpp.o
.PHONY : TripMate.cpp.o

TripMate.i: TripMate.cpp.i

.PHONY : TripMate.i

# target to preprocess a source file
TripMate.cpp.i:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/TripMate.cpp.i
.PHONY : TripMate.cpp.i

TripMate.s: TripMate.cpp.s

.PHONY : TripMate.s

# target to generate assembly for a file
TripMate.cpp.s:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/TripMate.cpp.s
.PHONY : TripMate.cpp.s

UImain.o: UImain.cpp.o

.PHONY : UImain.o

# target to build an object file
UImain.cpp.o:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/UImain.cpp.o
.PHONY : UImain.cpp.o

UImain.i: UImain.cpp.i

.PHONY : UImain.i

# target to preprocess a source file
UImain.cpp.i:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/UImain.cpp.i
.PHONY : UImain.cpp.i

UImain.s: UImain.cpp.s

.PHONY : UImain.s

# target to generate assembly for a file
UImain.cpp.s:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/UImain.cpp.s
.PHONY : UImain.cpp.s

Utils.o: Utils.cpp.o

.PHONY : Utils.o

# target to build an object file
Utils.cpp.o:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Utils.cpp.o
.PHONY : Utils.cpp.o

Utils.i: Utils.cpp.i

.PHONY : Utils.i

# target to preprocess a source file
Utils.cpp.i:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Utils.cpp.i
.PHONY : Utils.cpp.i

Utils.s: Utils.cpp.s

.PHONY : Utils.s

# target to generate assembly for a file
Utils.cpp.s:
	$(MAKE) -f CMakeFiles/MIEIC_CAl_PROJ.dir/build.make CMakeFiles/MIEIC_CAl_PROJ.dir/Utils.cpp.s
.PHONY : Utils.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... MIEIC_CAl_PROJ"
	@echo "... edit_cache"
	@echo "... Appointment.o"
	@echo "... Appointment.i"
	@echo "... Appointment.s"
	@echo "... Coordinates.o"
	@echo "... Coordinates.i"
	@echo "... Coordinates.s"
	@echo "... Graph.o"
	@echo "... Graph.i"
	@echo "... Graph.s"
	@echo "... GraphViewer/GraphicalInterface.o"
	@echo "... GraphViewer/GraphicalInterface.i"
	@echo "... GraphViewer/GraphicalInterface.s"
	@echo "... GraphViewer/connection.o"
	@echo "... GraphViewer/connection.i"
	@echo "... GraphViewer/connection.s"
	@echo "... GraphViewer/graphviewer.o"
	@echo "... GraphViewer/graphviewer.i"
	@echo "... GraphViewer/graphviewer.s"
	@echo "... Heuristics.o"
	@echo "... Heuristics.i"
	@echo "... Heuristics.s"
	@echo "... Schedule.o"
	@echo "... Schedule.i"
	@echo "... Schedule.s"
	@echo "... TestGraph.o"
	@echo "... TestGraph.i"
	@echo "... TestGraph.s"
	@echo "... TripMate.o"
	@echo "... TripMate.i"
	@echo "... TripMate.s"
	@echo "... UImain.o"
	@echo "... UImain.i"
	@echo "... UImain.s"
	@echo "... Utils.o"
	@echo "... Utils.i"
	@echo "... Utils.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

