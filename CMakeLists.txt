
cmake_minimum_required(VERSION 3.20)
project(GameApi)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable all warnings and debug information
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Wnull-dereference -Wformat=2 -Wunused -Woverloaded-virtual -Wduplicated-cond -Wduplicated-branches -fsanitize=address,undefined,leak -O0 -g3")

# Include directories
include_directories(header lib/ncurses++)

# Source files
file(GLOB_RECURSE GAMEAPI_SOURCES src/*.cpp)
file(GLOB_RECURSE NCURSES_INTERFACE_SOURCES lib/ncurses++/*.cpp)
file(GLOB_RECURSE GAMEAPI_HEADERS header/*.h)

# Add the executable
add_executable(GameApi main.cpp ${GAMEAPI_SOURCES} ${NCURSES_INTERFACE_SOURCES} ${GAMEAPI_HEADERS})

# Link libraries
target_link_libraries(GameApi ncurses)
