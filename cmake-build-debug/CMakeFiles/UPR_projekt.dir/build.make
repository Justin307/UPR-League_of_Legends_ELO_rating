# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\UPR_projekt.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\UPR_projekt.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\UPR_projekt.dir\flags.make

CMakeFiles\UPR_projekt.dir\main.c.obj: CMakeFiles\UPR_projekt.dir\flags.make
CMakeFiles\UPR_projekt.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/UPR_projekt.dir/main.c.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\UPR_projekt.dir\main.c.obj /FdCMakeFiles\UPR_projekt.dir\ /FS -c "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\main.c"
<<

CMakeFiles\UPR_projekt.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UPR_projekt.dir/main.c.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\UPR_projekt.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\main.c"
<<

CMakeFiles\UPR_projekt.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UPR_projekt.dir/main.c.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\UPR_projekt.dir\main.c.s /c "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\main.c"
<<

CMakeFiles\UPR_projekt.dir\lol.c.obj: CMakeFiles\UPR_projekt.dir\flags.make
CMakeFiles\UPR_projekt.dir\lol.c.obj: ..\lol.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/UPR_projekt.dir/lol.c.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\UPR_projekt.dir\lol.c.obj /FdCMakeFiles\UPR_projekt.dir\ /FS -c "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\lol.c"
<<

CMakeFiles\UPR_projekt.dir\lol.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UPR_projekt.dir/lol.c.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\UPR_projekt.dir\lol.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\lol.c"
<<

CMakeFiles\UPR_projekt.dir\lol.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UPR_projekt.dir/lol.c.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\UPR_projekt.dir\lol.c.s /c "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\lol.c"
<<

CMakeFiles\UPR_projekt.dir\htmlwriter.c.obj: CMakeFiles\UPR_projekt.dir\flags.make
CMakeFiles\UPR_projekt.dir\htmlwriter.c.obj: ..\htmlwriter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/UPR_projekt.dir/htmlwriter.c.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\UPR_projekt.dir\htmlwriter.c.obj /FdCMakeFiles\UPR_projekt.dir\ /FS -c "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\htmlwriter.c"
<<

CMakeFiles\UPR_projekt.dir\htmlwriter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UPR_projekt.dir/htmlwriter.c.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\UPR_projekt.dir\htmlwriter.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\htmlwriter.c"
<<

CMakeFiles\UPR_projekt.dir\htmlwriter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UPR_projekt.dir/htmlwriter.c.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\UPR_projekt.dir\htmlwriter.c.s /c "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\htmlwriter.c"
<<

CMakeFiles\UPR_projekt.dir\generalhelper.c.obj: CMakeFiles\UPR_projekt.dir\flags.make
CMakeFiles\UPR_projekt.dir\generalhelper.c.obj: ..\generalhelper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/UPR_projekt.dir/generalhelper.c.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\UPR_projekt.dir\generalhelper.c.obj /FdCMakeFiles\UPR_projekt.dir\ /FS -c "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\generalhelper.c"
<<

CMakeFiles\UPR_projekt.dir\generalhelper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UPR_projekt.dir/generalhelper.c.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\UPR_projekt.dir\generalhelper.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\generalhelper.c"
<<

CMakeFiles\UPR_projekt.dir\generalhelper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UPR_projekt.dir/generalhelper.c.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\UPR_projekt.dir\generalhelper.c.s /c "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\generalhelper.c"
<<

# Object files for target UPR_projekt
UPR_projekt_OBJECTS = \
"CMakeFiles\UPR_projekt.dir\main.c.obj" \
"CMakeFiles\UPR_projekt.dir\lol.c.obj" \
"CMakeFiles\UPR_projekt.dir\htmlwriter.c.obj" \
"CMakeFiles\UPR_projekt.dir\generalhelper.c.obj"

# External object files for target UPR_projekt
UPR_projekt_EXTERNAL_OBJECTS =

UPR_projekt.exe: CMakeFiles\UPR_projekt.dir\main.c.obj
UPR_projekt.exe: CMakeFiles\UPR_projekt.dir\lol.c.obj
UPR_projekt.exe: CMakeFiles\UPR_projekt.dir\htmlwriter.c.obj
UPR_projekt.exe: CMakeFiles\UPR_projekt.dir\generalhelper.c.obj
UPR_projekt.exe: CMakeFiles\UPR_projekt.dir\build.make
UPR_projekt.exe: CMakeFiles\UPR_projekt.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable UPR_projekt.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\UPR_projekt.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\UPR_projekt.dir\objects1.rsp @<<
 /out:UPR_projekt.exe /implib:UPR_projekt.lib /pdb:"C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\cmake-build-debug\UPR_projekt.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\UPR_projekt.dir\build: UPR_projekt.exe
.PHONY : CMakeFiles\UPR_projekt.dir\build

CMakeFiles\UPR_projekt.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\UPR_projekt.dir\cmake_clean.cmake
.PHONY : CMakeFiles\UPR_projekt.dir\clean

CMakeFiles\UPR_projekt.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt" "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt" "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\cmake-build-debug" "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\cmake-build-debug" "C:\Users\ondra\OneDrive\Dokumenty\C\1. semestr\UPR projekt\cmake-build-debug\CMakeFiles\UPR_projekt.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\UPR_projekt.dir\depend

