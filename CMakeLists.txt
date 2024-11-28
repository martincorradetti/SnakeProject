cmake_minimum_required(VERSION 3.30)
project(gameAPI)

set(CMAKE_CXX_STANDARD 20)

# Find and link the ncurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(gameAPI main.cpp
        ScreenManager.cpp
        ScreenManager.h
        Renderer.cpp
        Renderer.h
        InputHandler.cpp
        InputHandler.h
        ColorManager.cpp
        ColorManager.h
)

# Link the ncurses library to your executable
target_link_libraries(gameAPI ${CURSES_LIBRARIES} tinfo)
