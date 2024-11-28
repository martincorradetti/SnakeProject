#pragma once

class ColorManager {
public:
    void initialize();
    void setColorPair(short pair, short fg, short bg);
    void useColorPair(short pair);
    void resetColor();
};
