# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\Jetbrains\apps\CLion\ch-0\193.6494.38\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\Jetbrains\apps\CLion\ch-0\193.6494.38\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ashwi\CLionProjects\NumberSystemConversion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ashwi\CLionProjects\NumberSystemConversion\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NumberSystemConversion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NumberSystemConversion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NumberSystemConversion.dir/flags.make

CMakeFiles/NumberSystemConversion.dir/main.c.obj: CMakeFiles/NumberSystemConversion.dir/flags.make
CMakeFiles/NumberSystemConversion.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ashwi\CLionProjects\NumberSystemConversion\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/NumberSystemConversion.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\NumberSystemConversion.dir\main.c.obj   -c C:\Users\ashwi\CLionProjects\NumberSystemConversion\main.c

CMakeFiles/NumberSystemConversion.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NumberSystemConversion.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ashwi\CLionProjects\NumberSystemConversion\main.c > CMakeFiles\NumberSystemConversion.dir\main.c.i

CMakeFiles/NumberSystemConversion.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NumberSystemConversion.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ashwi\CLionProjects\NumberSystemConversion\main.c -o CMakeFiles\NumberSystemConversion.dir\main.c.s

# Object files for target NumberSystemConversion
NumberSystemConversion_OBJECTS = \
"CMakeFiles/NumberSystemConversion.dir/main.c.obj"

# External object files for target NumberSystemConversion
NumberSystemConversion_EXTERNAL_OBJECTS =

NumberSystemConversion.exe: CMakeFiles/NumberSystemConversion.dir/main.c.obj
NumberSystemConversion.exe: CMakeFiles/NumberSystemConversion.dir/build.make
NumberSystemConversion.exe: CMakeFiles/NumberSystemConversion.dir/linklibs.rsp
NumberSystemConversion.exe: CMakeFiles/NumberSystemConversion.dir/objects1.rsp
NumberSystemConversion.exe: CMakeFiles/NumberSystemConversion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ashwi\CLionProjects\NumberSystemConversion\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable NumberSystemConversion.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\NumberSystemConversion.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NumberSystemConversion.dir/build: NumberSystemConversion.exe

.PHONY : CMakeFiles/NumberSystemConversion.dir/build

CMakeFiles/NumberSystemConversion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NumberSystemConversion.dir\cmake_clean.cmake
.PHONY : CMakeFiles/NumberSystemConversion.dir/clean

CMakeFiles/NumberSystemConversion.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ashwi\CLionProjects\NumberSystemConversion C:\Users\ashwi\CLionProjects\NumberSystemConversion C:\Users\ashwi\CLionProjects\NumberSystemConversion\cmake-build-debug C:\Users\ashwi\CLionProjects\NumberSystemConversion\cmake-build-debug C:\Users\ashwi\CLionProjects\NumberSystemConversion\cmake-build-debug\CMakeFiles\NumberSystemConversion.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NumberSystemConversion.dir/depend

