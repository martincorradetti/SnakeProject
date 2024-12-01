#include "NCursesAPI.h"

int main()
{
    NCursesAPI game;

    game.clearScreen();
    game.println("Hello World!");
    game.getKey();
}