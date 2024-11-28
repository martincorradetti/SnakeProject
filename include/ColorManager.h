#pragma once

class ColorManager {
public:
    static void initialize();

    static void setColorPair(short pair, short fg, short bg);

    static void useColorPair(short pair);
    static void resetColor();
};
