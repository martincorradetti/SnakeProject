#include "InputHandler.h"
#include <ncurses.h>

int InputHandler::getKey()
{
    return getch();
}

void InputHandler::setTimeout(const int milliseconds)
{
    timeout(milliseconds);
}

void InputHandler::resetTimeout()
{
    timeout(-1);
}

KeyAction InputHandler::mapKey(const int key)
{
    switch (key) {
        case KEY_UP: return KeyAction::MOVE_UP;
        case KEY_DOWN: return KeyAction::MOVE_DOWN;
        case KEY_LEFT: return KeyAction::MOVE_LEFT;
        case KEY_RIGHT: return KeyAction::MOVE_RIGHT;
        case 'q': return KeyAction::EXIT;
        default: return KeyAction::NONE;
    }
}
