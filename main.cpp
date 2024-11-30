#include "GameAPI.h"

int main()
{
    GameAPI game;

    game.clearScreen();
    game.print("Hello World!");
    game.getKey();
}