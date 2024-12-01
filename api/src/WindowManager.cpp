#include "WindowManager.h"
#include <ncurses.h>

WindowManager::WindowManager() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, screenRows, screenCols);
}

WindowManager::~WindowManager() {
    endwin();
}

void WindowManager::clearScreen(const bool refreshImmediately) {
    clear();
    if (refreshImmediately) {
        refresh();
    }
}

void WindowManager::refreshScreen() {
    refresh();
}

void WindowManager::getScreenSize(int &rows, int &cols) const {
    rows = screenRows;
    cols = screenCols;
}

void WindowManager::drawBorder() {
    box(stdscr, 0, 0);
    refresh();
}
