#include "Renderer.h"
#include <ncurses.h>

void Renderer::drawText(int y, int x, const std::string &text) {
    mvprintw(y, x, text.c_str());
}

void Renderer::drawChar(int y, int x, char c) {
    mvaddch(y, x, c);
}

void Renderer::drawRectangle(int startY, int startX, int height, int width) {
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
