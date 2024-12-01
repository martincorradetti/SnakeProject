#pragma once

enum class KeyAction { MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, EXIT, NONE };

class InputHandler {
public:
    int getKey();
    void setTimeout(int milliseconds);
    void resetTimeout();
    KeyAction mapKey(int key);
};
