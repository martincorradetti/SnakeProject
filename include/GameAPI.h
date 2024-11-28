#pragma once

#include "ScreenManager.h"
#include "Renderer.h"
#include "InputHandler.h"
#include "ColorManager.h"

class GameAPI {
private:
    // Underlying components
    ScreenManager screenManager;
    Renderer renderer;
    InputHandler inputHandler;
    ColorManager colorManager;

    // Private constructor for singleton pattern
    GameAPI();

public:
    // Delete copy constructor and assignment operator to enforce singleton
    GameAPI(const GameAPI&) = delete;
    GameAPI& operator=(const GameAPI&) = delete;

    // Singleton instance accessor
    static GameAPI& getInstance();

    // Public methods (delegated to underlying classes)
    static void clearScreen(bool refreshImmediately = true);
    static void refreshScreen();

    static void drawBorder();
    void getScreenSize(int &rows, int &cols) const;

    static void drawText(int y, int x, const std::string &text);
    static void drawChar(int y, int x, char c);
    static void drawRectangle(int startY, int startX, int height, int width);

    static int getKey();
    static void setInputTimeout(int milliseconds);

    static void resetInputTimeout();

    void initColors();
    void setColorPair(short pair, short fg, short bg);
    void useColorPair(short pair);
    void resetColor();
};
