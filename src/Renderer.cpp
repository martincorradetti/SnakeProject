#include "Renderer.h"
#include <ncurses.h>

void Renderer::drawText(const int y, const int x, const std::string &text) {
    mvprintw(y, x, text.c_str());
}

void Renderer::drawChar(const int y, const int x, const char c) {
    mvaddch(y, x, c);
}

void Renderer::drawRectangle(const int startY, const int startX, const int height, const int width) {
    mvhline(startY, startX, 0, width);
    mvhline(startY + height, startX, 0, width);
    mvvline(startY, startX, 0, height);
    mvvline(startY, startX + width, 0, height);

    mvaddch(startY, startX, ACS_ULCORNER);
    mvaddch(startY, startX + width, ACS_URCORNER);
    mvaddch(startY + height, startX, ACS_LLCORNER);
    mvaddch(startY + height, startX + width, ACS_LRCORNER);

    refresh();
}
