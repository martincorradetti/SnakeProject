#include "Renderer.h"
#include <ncurses.h>

void Renderer::print(const char ch)
{
  	mvprintw(0, 0, "%c", ch);
}

void Renderer::print(const char* text) {
  if (text != nullptr)
  {
    mvprintw(0, 0, "%s", text);
  }
}

void Renderer::print(const int y, const int x, const char ch)
{
  mvprintw(y, x, "%c", ch);
}
void Renderer::print(const int y, const int x, const char* text) {
  if (text != nullptr)
  {
    	mvprintw(y, x, "%s", text);
  }
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
