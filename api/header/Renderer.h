#pragma once

class Renderer {
public:
    void print(const char* text);
    void print(char ch);
    void print(int y, int x, char ch);
    void print(int y, int x, const char* text);

    void println(const char* text);
    void println(char ch);
    void println(int y, int x, char ch);
    void println(int y, int x, const char* text);

    void drawRectangle(int startY, int startX, int height, int width);
};
