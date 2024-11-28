#include "GameAPI.h"

int main() {
    GameAPI& game = GameAPI::getInstance();

    int rows, cols;
    game.getScreenSize(rows, cols);

    bool running = true;
    GameAPI::drawBorder();

    while (running) {
        GameAPI::clearScreen(false);
        game.useColorPair(1);
        GameAPI::drawText(rows / 2, cols / 2 - 5, "Snake Game");
        GameAPI::refreshScreen();

        int key = GameAPI::getKey();
        if (key == 'q') {
            running = false;
        }

        GameAPI::setInputTimeout(100); // Control game speed
    }
}
