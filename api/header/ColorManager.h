#pragma once

class ColorManager {
public:

    ColorManager();

    void setColorPair(short pair, short fg, short bg);
    void useColorPair(short pair);
    void resetColor();
};
