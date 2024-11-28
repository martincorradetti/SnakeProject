#pragma once

enum class KeyAction { MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, EXIT, NONE };

class InputHandler {
public:
    static int getKey();
    static void setTimeout(int milliseconds);
    static void resetTimeout();
    static KeyAction mapKey(int key);
};
