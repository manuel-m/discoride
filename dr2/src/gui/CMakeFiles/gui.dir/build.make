# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/jam/Bureau/dr2.05

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jam/Bureau/dr2.05

# Include any dependencies generated for this target.
include src/gui/CMakeFiles/gui.dir/depend.make

# Include the progress variables for this target.
include src/gui/CMakeFiles/gui.dir/progress.make

# Include the compile flags for this target's objects.
include src/gui/CMakeFiles/gui.dir/flags.make

src/gui/CMakeFiles/gui.dir/rpanel_dock0.c.o: src/gui/CMakeFiles/gui.dir/flags.make
src/gui/CMakeFiles/gui.dir/rpanel_dock0.c.o: src/gui/rpanel_dock0.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jam/Bureau/dr2.05/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/gui/CMakeFiles/gui.dir/rpanel_dock0.c.o"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/gui.dir/rpanel_dock0.c.o   -c /home/jam/Bureau/dr2.05/src/gui/rpanel_dock0.c

src/gui/CMakeFiles/gui.dir/rpanel_dock0.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gui.dir/rpanel_dock0.c.i"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jam/Bureau/dr2.05/src/gui/rpanel_dock0.c > CMakeFiles/gui.dir/rpanel_dock0.c.i

src/gui/CMakeFiles/gui.dir/rpanel_dock0.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gui.dir/rpanel_dock0.c.s"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jam/Bureau/dr2.05/src/gui/rpanel_dock0.c -o CMakeFiles/gui.dir/rpanel_dock0.c.s

src/gui/CMakeFiles/gui.dir/rpanel_dock0.c.o.requires:
.PHONY : src/gui/CMakeFiles/gui.dir/rpanel_dock0.c.o.requires

src/gui/CMakeFiles/gui.dir/rpanel_dock0.c.o.provides: src/gui/CMakeFiles/gui.dir/rpanel_dock0.c.o.requires
	$(MAKE) -f src/gui/CMakeFiles/gui.dir/build.make src/gui/CMakeFiles/gui.dir/rpanel_dock0.c.o.provides.build
.PHONY : src/gui/CMakeFiles/gui.dir/rpanel_dock0.c.o.provides

src/gui/CMakeFiles/gui.dir/rpanel_dock0.c.o.provides.build: src/gui/CMakeFiles/gui.dir/rpanel_dock0.c.o

src/gui/CMakeFiles/gui.dir/rpanel_dock1.c.o: src/gui/CMakeFiles/gui.dir/flags.make
src/gui/CMakeFiles/gui.dir/rpanel_dock1.c.o: src/gui/rpanel_dock1.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jam/Bureau/dr2.05/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/gui/CMakeFiles/gui.dir/rpanel_dock1.c.o"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/gui.dir/rpanel_dock1.c.o   -c /home/jam/Bureau/dr2.05/src/gui/rpanel_dock1.c

src/gui/CMakeFiles/gui.dir/rpanel_dock1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gui.dir/rpanel_dock1.c.i"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jam/Bureau/dr2.05/src/gui/rpanel_dock1.c > CMakeFiles/gui.dir/rpanel_dock1.c.i

src/gui/CMakeFiles/gui.dir/rpanel_dock1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gui.dir/rpanel_dock1.c.s"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jam/Bureau/dr2.05/src/gui/rpanel_dock1.c -o CMakeFiles/gui.dir/rpanel_dock1.c.s

src/gui/CMakeFiles/gui.dir/rpanel_dock1.c.o.requires:
.PHONY : src/gui/CMakeFiles/gui.dir/rpanel_dock1.c.o.requires

src/gui/CMakeFiles/gui.dir/rpanel_dock1.c.o.provides: src/gui/CMakeFiles/gui.dir/rpanel_dock1.c.o.requires
	$(MAKE) -f src/gui/CMakeFiles/gui.dir/build.make src/gui/CMakeFiles/gui.dir/rpanel_dock1.c.o.provides.build
.PHONY : src/gui/CMakeFiles/gui.dir/rpanel_dock1.c.o.provides

src/gui/CMakeFiles/gui.dir/rpanel_dock1.c.o.provides.build: src/gui/CMakeFiles/gui.dir/rpanel_dock1.c.o

src/gui/CMakeFiles/gui.dir/rpanel_mix.c.o: src/gui/CMakeFiles/gui.dir/flags.make
src/gui/CMakeFiles/gui.dir/rpanel_mix.c.o: src/gui/rpanel_mix.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jam/Bureau/dr2.05/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/gui/CMakeFiles/gui.dir/rpanel_mix.c.o"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/gui.dir/rpanel_mix.c.o   -c /home/jam/Bureau/dr2.05/src/gui/rpanel_mix.c

src/gui/CMakeFiles/gui.dir/rpanel_mix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gui.dir/rpanel_mix.c.i"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jam/Bureau/dr2.05/src/gui/rpanel_mix.c > CMakeFiles/gui.dir/rpanel_mix.c.i

src/gui/CMakeFiles/gui.dir/rpanel_mix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gui.dir/rpanel_mix.c.s"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jam/Bureau/dr2.05/src/gui/rpanel_mix.c -o CMakeFiles/gui.dir/rpanel_mix.c.s

src/gui/CMakeFiles/gui.dir/rpanel_mix.c.o.requires:
.PHONY : src/gui/CMakeFiles/gui.dir/rpanel_mix.c.o.requires

src/gui/CMakeFiles/gui.dir/rpanel_mix.c.o.provides: src/gui/CMakeFiles/gui.dir/rpanel_mix.c.o.requires
	$(MAKE) -f src/gui/CMakeFiles/gui.dir/build.make src/gui/CMakeFiles/gui.dir/rpanel_mix.c.o.provides.build
.PHONY : src/gui/CMakeFiles/gui.dir/rpanel_mix.c.o.provides

src/gui/CMakeFiles/gui.dir/rpanel_mix.c.o.provides.build: src/gui/CMakeFiles/gui.dir/rpanel_mix.c.o

src/gui/CMakeFiles/gui.dir/rpanel_playlist.c.o: src/gui/CMakeFiles/gui.dir/flags.make
src/gui/CMakeFiles/gui.dir/rpanel_playlist.c.o: src/gui/rpanel_playlist.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jam/Bureau/dr2.05/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/gui/CMakeFiles/gui.dir/rpanel_playlist.c.o"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/gui.dir/rpanel_playlist.c.o   -c /home/jam/Bureau/dr2.05/src/gui/rpanel_playlist.c

src/gui/CMakeFiles/gui.dir/rpanel_playlist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gui.dir/rpanel_playlist.c.i"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jam/Bureau/dr2.05/src/gui/rpanel_playlist.c > CMakeFiles/gui.dir/rpanel_playlist.c.i

src/gui/CMakeFiles/gui.dir/rpanel_playlist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gui.dir/rpanel_playlist.c.s"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jam/Bureau/dr2.05/src/gui/rpanel_playlist.c -o CMakeFiles/gui.dir/rpanel_playlist.c.s

src/gui/CMakeFiles/gui.dir/rpanel_playlist.c.o.requires:
.PHONY : src/gui/CMakeFiles/gui.dir/rpanel_playlist.c.o.requires

src/gui/CMakeFiles/gui.dir/rpanel_playlist.c.o.provides: src/gui/CMakeFiles/gui.dir/rpanel_playlist.c.o.requires
	$(MAKE) -f src/gui/CMakeFiles/gui.dir/build.make src/gui/CMakeFiles/gui.dir/rpanel_playlist.c.o.provides.build
.PHONY : src/gui/CMakeFiles/gui.dir/rpanel_playlist.c.o.provides

src/gui/CMakeFiles/gui.dir/rpanel_playlist.c.o.provides.build: src/gui/CMakeFiles/gui.dir/rpanel_playlist.c.o

src/gui/CMakeFiles/gui.dir/rpanels.c.o: src/gui/CMakeFiles/gui.dir/flags.make
src/gui/CMakeFiles/gui.dir/rpanels.c.o: src/gui/rpanels.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jam/Bureau/dr2.05/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/gui/CMakeFiles/gui.dir/rpanels.c.o"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/gui.dir/rpanels.c.o   -c /home/jam/Bureau/dr2.05/src/gui/rpanels.c

src/gui/CMakeFiles/gui.dir/rpanels.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gui.dir/rpanels.c.i"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jam/Bureau/dr2.05/src/gui/rpanels.c > CMakeFiles/gui.dir/rpanels.c.i

src/gui/CMakeFiles/gui.dir/rpanels.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gui.dir/rpanels.c.s"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jam/Bureau/dr2.05/src/gui/rpanels.c -o CMakeFiles/gui.dir/rpanels.c.s

src/gui/CMakeFiles/gui.dir/rpanels.c.o.requires:
.PHONY : src/gui/CMakeFiles/gui.dir/rpanels.c.o.requires

src/gui/CMakeFiles/gui.dir/rpanels.c.o.provides: src/gui/CMakeFiles/gui.dir/rpanels.c.o.requires
	$(MAKE) -f src/gui/CMakeFiles/gui.dir/build.make src/gui/CMakeFiles/gui.dir/rpanels.c.o.provides.build
.PHONY : src/gui/CMakeFiles/gui.dir/rpanels.c.o.provides

src/gui/CMakeFiles/gui.dir/rpanels.c.o.provides.build: src/gui/CMakeFiles/gui.dir/rpanels.c.o

src/gui/CMakeFiles/gui.dir/rpanel_sidebar.c.o: src/gui/CMakeFiles/gui.dir/flags.make
src/gui/CMakeFiles/gui.dir/rpanel_sidebar.c.o: src/gui/rpanel_sidebar.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jam/Bureau/dr2.05/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/gui/CMakeFiles/gui.dir/rpanel_sidebar.c.o"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/gui.dir/rpanel_sidebar.c.o   -c /home/jam/Bureau/dr2.05/src/gui/rpanel_sidebar.c

src/gui/CMakeFiles/gui.dir/rpanel_sidebar.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gui.dir/rpanel_sidebar.c.i"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jam/Bureau/dr2.05/src/gui/rpanel_sidebar.c > CMakeFiles/gui.dir/rpanel_sidebar.c.i

src/gui/CMakeFiles/gui.dir/rpanel_sidebar.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gui.dir/rpanel_sidebar.c.s"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jam/Bureau/dr2.05/src/gui/rpanel_sidebar.c -o CMakeFiles/gui.dir/rpanel_sidebar.c.s

src/gui/CMakeFiles/gui.dir/rpanel_sidebar.c.o.requires:
.PHONY : src/gui/CMakeFiles/gui.dir/rpanel_sidebar.c.o.requires

src/gui/CMakeFiles/gui.dir/rpanel_sidebar.c.o.provides: src/gui/CMakeFiles/gui.dir/rpanel_sidebar.c.o.requires
	$(MAKE) -f src/gui/CMakeFiles/gui.dir/build.make src/gui/CMakeFiles/gui.dir/rpanel_sidebar.c.o.provides.build
.PHONY : src/gui/CMakeFiles/gui.dir/rpanel_sidebar.c.o.provides

src/gui/CMakeFiles/gui.dir/rpanel_sidebar.c.o.provides.build: src/gui/CMakeFiles/gui.dir/rpanel_sidebar.c.o

src/gui/CMakeFiles/gui.dir/rpanel_waves.c.o: src/gui/CMakeFiles/gui.dir/flags.make
src/gui/CMakeFiles/gui.dir/rpanel_waves.c.o: src/gui/rpanel_waves.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jam/Bureau/dr2.05/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/gui/CMakeFiles/gui.dir/rpanel_waves.c.o"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/gui.dir/rpanel_waves.c.o   -c /home/jam/Bureau/dr2.05/src/gui/rpanel_waves.c

src/gui/CMakeFiles/gui.dir/rpanel_waves.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gui.dir/rpanel_waves.c.i"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jam/Bureau/dr2.05/src/gui/rpanel_waves.c > CMakeFiles/gui.dir/rpanel_waves.c.i

src/gui/CMakeFiles/gui.dir/rpanel_waves.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gui.dir/rpanel_waves.c.s"
	cd /home/jam/Bureau/dr2.05/src/gui && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jam/Bureau/dr2.05/src/gui/rpanel_waves.c -o CMakeFiles/gui.dir/rpanel_waves.c.s

src/gui/CMakeFiles/gui.dir/rpanel_waves.c.o.requires:
.PHONY : src/gui/CMakeFiles/gui.dir/rpanel_waves.c.o.requires

src/gui/CMakeFiles/gui.dir/rpanel_waves.c.o.provides: src/gui/CMakeFiles/gui.dir/rpanel_waves.c.o.requires
	$(MAKE) -f src/gui/CMakeFiles/gui.dir/build.make src/gui/CMakeFiles/gui.dir/rpanel_waves.c.o.provides.build
.PHONY : src/gui/CMakeFiles/gui.dir/rpanel_waves.c.o.provides

src/gui/CMakeFiles/gui.dir/rpanel_waves.c.o.provides.build: src/gui/CMakeFiles/gui.dir/rpanel_waves.c.o

# Object files for target gui
gui_OBJECTS = \
"CMakeFiles/gui.dir/rpanel_dock0.c.o" \
"CMakeFiles/gui.dir/rpanel_dock1.c.o" \
"CMakeFiles/gui.dir/rpanel_mix.c.o" \
"CMakeFiles/gui.dir/rpanel_playlist.c.o" \
"CMakeFiles/gui.dir/rpanels.c.o" \
"CMakeFiles/gui.dir/rpanel_sidebar.c.o" \
"CMakeFiles/gui.dir/rpanel_waves.c.o"

# External object files for target gui
gui_EXTERNAL_OBJECTS =

src/gui/libgui.a: src/gui/CMakeFiles/gui.dir/rpanel_dock0.c.o
src/gui/libgui.a: src/gui/CMakeFiles/gui.dir/rpanel_dock1.c.o
src/gui/libgui.a: src/gui/CMakeFiles/gui.dir/rpanel_mix.c.o
src/gui/libgui.a: src/gui/CMakeFiles/gui.dir/rpanel_playlist.c.o
src/gui/libgui.a: src/gui/CMakeFiles/gui.dir/rpanels.c.o
src/gui/libgui.a: src/gui/CMakeFiles/gui.dir/rpanel_sidebar.c.o
src/gui/libgui.a: src/gui/CMakeFiles/gui.dir/rpanel_waves.c.o
src/gui/libgui.a: src/gui/CMakeFiles/gui.dir/build.make
src/gui/libgui.a: src/gui/CMakeFiles/gui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libgui.a"
	cd /home/jam/Bureau/dr2.05/src/gui && $(CMAKE_COMMAND) -P CMakeFiles/gui.dir/cmake_clean_target.cmake
	cd /home/jam/Bureau/dr2.05/src/gui && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/gui/CMakeFiles/gui.dir/build: src/gui/libgui.a
.PHONY : src/gui/CMakeFiles/gui.dir/build

src/gui/CMakeFiles/gui.dir/requires: src/gui/CMakeFiles/gui.dir/rpanel_dock0.c.o.requires
src/gui/CMakeFiles/gui.dir/requires: src/gui/CMakeFiles/gui.dir/rpanel_dock1.c.o.requires
src/gui/CMakeFiles/gui.dir/requires: src/gui/CMakeFiles/gui.dir/rpanel_mix.c.o.requires
src/gui/CMakeFiles/gui.dir/requires: src/gui/CMakeFiles/gui.dir/rpanel_playlist.c.o.requires
src/gui/CMakeFiles/gui.dir/requires: src/gui/CMakeFiles/gui.dir/rpanels.c.o.requires
src/gui/CMakeFiles/gui.dir/requires: src/gui/CMakeFiles/gui.dir/rpanel_sidebar.c.o.requires
src/gui/CMakeFiles/gui.dir/requires: src/gui/CMakeFiles/gui.dir/rpanel_waves.c.o.requires
.PHONY : src/gui/CMakeFiles/gui.dir/requires

src/gui/CMakeFiles/gui.dir/clean:
	cd /home/jam/Bureau/dr2.05/src/gui && $(CMAKE_COMMAND) -P CMakeFiles/gui.dir/cmake_clean.cmake
.PHONY : src/gui/CMakeFiles/gui.dir/clean

src/gui/CMakeFiles/gui.dir/depend:
	cd /home/jam/Bureau/dr2.05 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jam/Bureau/dr2.05 /home/jam/Bureau/dr2.05/src/gui /home/jam/Bureau/dr2.05 /home/jam/Bureau/dr2.05/src/gui /home/jam/Bureau/dr2.05/src/gui/CMakeFiles/gui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/gui/CMakeFiles/gui.dir/depend

