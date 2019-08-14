cmake_minimum_required(VERSION 3.5)

# Set project name and force C language
project(cellular_automata C)

# Compile in "bin" folder
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Set C standard
set(CMAKE_C_STANDARD 99)

# Compile flags
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

# Select "src" folder
set(src_path "${CMAKE_SOURCE_DIR}/src/")
message(STATUS "project_src_path=${src_path}")

# Set source files list
set(SOURCE_FILES 
    ${src_path}main.c
)
message(STATUS "project_files_list=${SOURCE_FILES}")

# Create executable (all source files directly in it)
add_executable(cellular_automata ${SOURCE_FILES})