#include "NCursesAPI.h"

int main()
{
    NCursesAPI game;

    game.clearScreen();
    //game.println("Hello World!");
    game.drawRectangle(0, 0, 10, 10);
    game.getKey();
}