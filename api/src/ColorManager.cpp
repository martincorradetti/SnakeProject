#include "ColorManager.h"
#include <ncurses.h>

ColorManager::ColorManager()
{
    start_color(); // Enable color functionality in ncurses
}

void ColorManager::setColorPair(const short pair, const short fg, const short bg)
{
    init_pair(pair, fg, bg); // Define a color pair
}

void ColorManager::useColorPair(const short pair)
{
    attron(COLOR_PAIR(pair)); // Activate the specified color pair
}

void ColorManager::resetColor()
{
    attroff(A_COLOR); // Disable all color attributes
}
