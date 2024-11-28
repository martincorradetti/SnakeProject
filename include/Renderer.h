#pragma once
#include <string>

class Renderer {
public:
    static void drawText(int y, int x, const std::string &text);
    static void drawChar(int y, int x, char c);
    static void drawRectangle(int startY, int startX, int height, int width);
};
