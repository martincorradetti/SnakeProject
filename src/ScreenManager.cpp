#include "ScreenManager.h"
#include <ncurses.h>

ScreenManager::ScreenManager() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, screenRows, screenCols);
}

ScreenManager::~ScreenManager() {
    endwin();
}

void ScreenManager::clearScreen(const bool refreshImmediately) {
    clear();
    if (refreshImmediately) {
        refresh();
    }
}

void ScreenManager::refreshScreen() {
    refresh();
}

void ScreenManager::getScreenSize(int &rows, int &cols) const {
    rows = screenRows;
    cols = screenCols;
}

void ScreenManager::drawBorder() {
    box(stdscr, 0, 0);
    refresh();
}
