#include "WindowManager.h"

// Constructor: Initializes ncurses and stores the given screen dimensions
WindowManager::WindowManager(const Screen& screen)
    : screen(screen) {
    initscr();        // Initialize ncurses
    curs_set(0);      // Hide the cursor
}

// Destructor: Cleans up ncurses resources
WindowManager::~WindowManager() {
    endwin();         // Restore terminal to normal settings
}

// Clears the terminal screen
void WindowManager::clearScreen(bool refreshImmediately) {
    clear();          // Clear the ncurses screen buffer
    if (refreshImmediately) {
        refresh();    // Apply the changes to the terminal
    }
}

// Refreshes the terminal screen
void WindowManager::refreshScreen() {
    refresh();        // Apply any pending updates to the terminal
}

// Retrieves the current screen size
const Screen& WindowManager::getScreenSize() const {
    return screen;    // Return the stored screen dimensions
}

// Draws a border around the terminal window
void WindowManager::drawBorder() {
    box(stdscr, 0, 0); // Draw a simple rectangular border
    refresh();        // Display the border on the terminal
}
