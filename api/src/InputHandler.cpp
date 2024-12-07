#include "InputHandler.h"
#include <ncurses.h>

InputHandler::InputHandler() {
    cbreak(); // Disable line buffering for immediate input processing
    noecho(); // Turn off echoing of typed characters
    keypad(stdscr, TRUE); // Enable special keys like arrows and function keys
}

int InputHandler::getKey()
{
    return getch(); // Wait for and return the next key press
}

void InputHandler::setTimeout(const int milliseconds)
{
    timeout(milliseconds); // Set input timeout (non-blocking)
}

void InputHandler::resetTimeout()
{
    timeout(-1); // Reset input mode to blocking
}

KeyAction InputHandler::mapKey(const int key)
{
    // Map key codes to corresponding actions
    switch (key) {
        case KEY_UP: return KeyAction::MOVE_UP;
        case KEY_DOWN: return KeyAction::MOVE_DOWN;
        case KEY_LEFT: return KeyAction::MOVE_LEFT;
        case KEY_RIGHT: return KeyAction::MOVE_RIGHT;
        case 'q': return KeyAction::EXIT;
        default: return KeyAction::NONE; // No action for unrecognized keys
    }
}
