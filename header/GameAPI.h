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

public:
  	GameAPI();
    ~GameAPI();

    // Public methods (delegated to underlying classes)
    void clearScreen(bool refreshImmediately = true);
    void refreshScreen();

    void drawBorder();
    void getScreenSize(int &rows, int &cols) const;

    void print(int y, int x, char ch);
    void print(const char* text);
    void print(char ch);
 	void print(int y, int x, const char* text);

    void drawRectangle(int startY, int startX, int height, int width);

    int getKey();
    void setInputTimeout(int milliseconds);

    void resetInputTimeout();

    void initColors();
    void setColorPair(short pair, short fg, short bg);
    void useColorPair(short pair);
    void resetColor();
};
