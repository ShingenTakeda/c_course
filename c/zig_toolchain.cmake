#Make tool that get the path to zig to be put where it is needed

# Get zig executable path using bootstrap script
execute_process(
    COMMAND python3 ${CMAKE_CURRENT_LIST_DIR}/bootstrap.py
    OUTPUT_VARIABLE ZIG_EXE
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE ZIG_EXE_RESULT
)

if(NOT ZIG_EXE_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to get zig executable path")
endif()

#C compiler
set(CMAKE_C_COMPILER ${ZIG_EXE})
set(CMAKE_C_COMPILER_ARG1 cc)

#C++ compiler
set(CMAKE_CXX_COMPILER ${ZIG_EXE})
set(CMAKE_CXX_COMPILER_ARG1 c++)


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

