#include "ColorManager.h"
#include <ncurses.h>

void ColorManager::initialize() {
    if (has_colors()) {
        start_color();
    }
}

void ColorManager::setColorPair(short pair, short fg, short bg) {
    init_pair(pair, fg, bg);
}

void ColorManager::useColorPair(short pair) {
    attron(COLOR_PAIR(pair));
}

void ColorManager::resetColor() {
    attroff(A_COLOR);
}
