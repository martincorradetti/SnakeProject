#include <ncurses.h>

#include "ScreenManager.h"
#include "Renderer.h"
#include "InputHandler.h"
#include "ColorManager.h"

int main() {
    ScreenManager screen;
    Renderer renderer;
    InputHandler input;
    ColorManager colors;

    colors.initialize();
    colors.setColorPair(1, COLOR_RED, COLOR_BLACK);

    int rows, cols;
    screen.getScreenSize(rows, cols);

    bool running = true;
    screen.drawBorder();

    while (running) {
        screen.clearScreen(false);

        colors.useColorPair(1);
        renderer.drawText(rows / 2, cols / 2 - 5, "Snake Game");
        screen.refreshScreen();

        int key = input.getKey();
        if (key == 'q') {
            running = false;
        } else {
            KeyAction action = input.mapKey(key);
            // Handle the action here
        }

        input.setTimeout(100); // Control speed
    }

    return 0;
}
