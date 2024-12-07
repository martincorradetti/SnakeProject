#include "Renderer.h"
#include <stdexcept>

// Constructor: Initializes the screen dimensions from WindowManager
Renderer::Renderer(const WindowManager& wm)
    : screen(wm.getScreenSize()) {}

// Print a single character at the top-left corner
void Renderer::print(const char ch) {
    mvprintw(0, 0, "%c", ch);
}

// Print a string of text at the top-left corner
void Renderer::print(const char* text) {
    if (text != nullptr) {
        mvprintw(0, 0, "%s", text);
    }
}

// Print a single character at a specific position
void Renderer::print(int y, int x, char ch) {
    mvprintw(y, x, "%c", ch);
}

// Print a string of text at a specific position
void Renderer::print(int y, int x, const char* text) {
    if (text != nullptr) {
        mvprintw(y, x, "%s", text);
    }
}

// Print a single character with a newline at the top-left corner
void Renderer::println(char ch) {
    mvprintw(0, 0, "%c", ch);
    move(1, 0);
}

// Print a string of text with a newline at the top-left corner
void Renderer::println(const char* text) {
    if (text != nullptr) {
        int y, x;
        getyx(stdscr, y, x);
        mvprintw(y, x, "%s", text);
        if (y + 1 < screen.rows) {
            move(y + 1, 0);
        } else {
            scroll(stdscr);
        }
    }
}

// Print a single character with a newline at a specific position
void Renderer::println(int y, int x, char ch) {
    mvprintw(y, x, "%c", ch);
    move(y + 1, 0);
}

// Print a string of text with a newline at a specific position
void Renderer::println(int y, int x, const char* text) {
    if (text != nullptr) {
        mvprintw(y, x, "%s", text);
        if (y + 1 < screen.rows) {
            move(y + 1, 0);
        } else {
            scroll(stdscr);
        }
    }
}

// Draw a rectangle using ncurses line-drawing characters
void Renderer::drawRectangle(int startY, int startX, int height, int width, bool refreshImmediately) {
    if (startY < 0 || startX < 0 || startY + height > screen.rows || startX + width > screen.cols) {
        throw std::out_of_range("Rectangle dimensions exceed screen size");
    }

    mvhline(startY, startX, 0, width);
    mvhline(startY + height - 1, startX, 0, width);
    mvvline(startY, startX, 0, height);
    mvvline(startY, startX + width - 1, 0, height);

    mvaddch(startY, startX, ACS_ULCORNER);
    mvaddch(startY, startX + width - 1, ACS_URCORNER);
    mvaddch(startY + height - 1, startX, ACS_LLCORNER);
    mvaddch(startY + height - 1, startX + width - 1, ACS_LRCORNER);

    if (refreshImmediately) {
        refresh();
    }
}
