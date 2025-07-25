cmake_minimum_required(VERSION 4.0)


set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/zig_toolchain.cmake")

project(c_classes LANGUAGES C)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include Zig libc headers for language server support
# These are set by the toolchain file, but we can also set them here for clarity
if(DEFINED ZIG_STD_DIR)
    if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
        include_directories(SYSTEM 
            ${ZIG_STD_DIR}/libc/include
            ${ZIG_STD_DIR}/libc/include/generic-musl
            ${ZIG_STD_DIR}/libc/include/x86_64-linux-musl
        )
    elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
        include_directories(SYSTEM 
            ${ZIG_STD_DIR}/libc/include
            ${ZIG_STD_DIR}/libc/include/any-windows-any
            ${ZIG_STD_DIR}/libc/include/x86_64-windows-gnu
        )
    elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
        include_directories(SYSTEM 
            ${ZIG_STD_DIR}/libc/include
            ${ZIG_STD_DIR}/libc/include/any-darwin-any
            ${ZIG_STD_DIR}/libc/include/x86_64-macos
        )
    else()
        include_directories(SYSTEM ${ZIG_STD_DIR}/libc/include)
    endif()
endif()

# Dependencies
set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(raylib)
  endif()
endif()

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
add_subdirectory(basics)
add_subdirectory(graphical_explanations_and_real_use_cases)
