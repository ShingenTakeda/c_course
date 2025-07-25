#Make tool that get the path to zig to be put where it is needed

# Get zig executable path and stdlib directory using bootstrap script
execute_process(
    COMMAND python3 ${CMAKE_CURRENT_LIST_DIR}/bootstrap.py
    OUTPUT_VARIABLE ZIG_BOOTSTRAP_OUTPUT
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE ZIG_BOOTSTRAP_RESULT
)

if(NOT ZIG_BOOTSTRAP_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to get zig environment info")
endif()

# Parse ZIG_EXE and ZIG_STD_DIR from the output
string(REGEX MATCH "ZIG_EXE=([^\n]+)" _zig_exe_match "${ZIG_BOOTSTRAP_OUTPUT}")
string(REGEX REPLACE ".*ZIG_EXE=([^\n]+).*" "\\1" ZIG_EXE "${_zig_exe_match}")

string(REGEX MATCH "ZIG_STD_DIR=([^\n]+)" _zig_std_dir_match "${ZIG_BOOTSTRAP_OUTPUT}")
string(REGEX REPLACE ".*ZIG_STD_DIR=([^\n]+).*" "\\1" ZIG_STD_DIR "${_zig_std_dir_match}")

if(NOT ZIG_EXE)
    message(FATAL_ERROR "Failed to parse ZIG_EXE from bootstrap output")
endif()
if(NOT ZIG_STD_DIR)
    message(FATAL_ERROR "Failed to parse ZIG_STD_DIR from bootstrap output")
endif()

# Use TARGET variable if provided, otherwise default to native
if(DEFINED TARGET)
    set(ZIG_TARGET ${TARGET})
else()
    # Default to native if no target specified
    set(ZIG_TARGET "native")
endif()

#C compiler
set(CMAKE_C_COMPILER ${ZIG_EXE})
set(CMAKE_C_COMPILER_ARG1 cc)
set(CMAKE_C_COMPILER_ARG2 -target)
set(CMAKE_C_COMPILER_ARG3 ${ZIG_TARGET})

#C++ compiler
set(CMAKE_CXX_COMPILER ${ZIG_EXE})
set(CMAKE_CXX_COMPILER_ARG1 c++)
set(CMAKE_CXX_COMPILER_ARG2 -target)
set(CMAKE_CXX_COMPILER_ARG3 ${ZIG_TARGET})


if(CMAKE_HOST_WIN32)
    set(SCRIPT_SUFFIX ".cmd")
else()
    set(SCRIPT_SUFFIX ".sh")
endif()

#Ar
set(CMAKE_AR ${CMAKE_CURRENT_LIST_DIR}/toolchain/zig_ar${SCRIPT_SUFFIX} CACHE FILEPATH "Zig AR")
set(CMAKE_DLLTOOL ${CMAKE_CURRENT_LIST_DIR}/toolchain/zig_dlltool${SCRIPT_SUFFIX} CACHE FILEPATH "Zig DLLTOOL")
set(CMAKE_RANLIB ${CMAKE_CURRENT_LIST_DIR}/toolchain/zig_ranlib${SCRIPT_SUFFIX} CACHE FILEPATH "Zig RANLIB")
set(CMAKE_RC ${CMAKE_CURRENT_LIST_DIR}/toolchain/zig_rc${SCRIPT_SUFFIX} CACHE FILEPATH "Zig RC")

set(CMAKE_C_COMPILER_TARGET ${TARGET})
set(CMAKE_CXX_COMPILER_TARGET ${TARGET})

#Defualt standarts
set(CMAKE_C_STANDARD_COMPUTED_DEFAULT 11)
set(CMAKE_CXX_STANDARD_COMPUTED_DEFAULT 17)

# Optional: remove LTO or other flags CMake might try
set(CMAKE_C_FLAGS_INIT "")
set(CMAKE_CXX_FLAGS_INIT "")

if (CMAKE_HOST_UNIX)
	set(CMAKE_C_LINKER_DEPFILE_SUPPORTED FALSE)
	set(CMAKE_CXX_LINKER_DEPFILE_SUPPORTED FALSE)
endif()

# Set Zig libc include directories per system
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(ZIG_LIBC_INCLUDE_DIRS
        ${ZIG_STD_DIR}/libc/include
        ${ZIG_STD_DIR}/libc/include/generic-musl
        ${ZIG_STD_DIR}/libc/include/x86_64-linux-musl
    )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(ZIG_LIBC_INCLUDE_DIRS
        ${ZIG_STD_DIR}/libc/include
        ${ZIG_STD_DIR}/libc/include/any-windows-any
        ${ZIG_STD_DIR}/libc/include/x86_64-windows-gnu
    )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(ZIG_LIBC_INCLUDE_DIRS
        ${ZIG_STD_DIR}/libc/include
        ${ZIG_STD_DIR}/libc/include/any-darwin-any
        ${ZIG_STD_DIR}/libc/include/x86_64-macos
    )
else()
    set(ZIG_LIBC_INCLUDE_DIRS ${ZIG_STD_DIR}/libc/include)
endif()

# Add these as SYSTEM include directories for all targets
include_directories(SYSTEM ${ZIG_LIBC_INCLUDE_DIRS})

