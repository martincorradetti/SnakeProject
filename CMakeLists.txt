cmake_minimum_required(VERSION 3.30)
project(gameAPI)

set(CMAKE_CXX_STANDARD 20)

# Find and link the ncurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(gameAPI src/main.cpp
        src/ScreenManager.cpp
        include/ScreenManager.h
        src/Renderer.cpp
        include/Renderer.h
        src/InputHandler.cpp
        include/InputHandler.h
        ColorManager.cpp
        include/ColorManager.h
        src/GameAPI.cpp
        include/GameAPI.h
)

# Link the ncurses library to your executable
target_link_libraries(gameAPI ${CURSES_LIBRARIES} tinfo)
