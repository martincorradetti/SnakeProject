/**
 * @brief Handles input events and key mappings for the application.
 *
 * This class is responsible for managing input settings, such as timeouts,
 * reading user input, and mapping keypresses to predefined actions.
 */
#pragma once

/**
 * @brief Enum representing possible key actions.
 *
 * These actions correspond to user input for controlling the application,
 * such as directional movement or exiting the program.
 */
enum class KeyAction {
    MOVE_UP,    /**< Move up action. */
    MOVE_DOWN,  /**< Move down action. */
    MOVE_LEFT,  /**< Move left action. */
    MOVE_RIGHT, /**< Move right action. */
    EXIT,       /**< Exit the application. */
    NONE        /**< No action. */
};

/**
 * @brief Manages input settings and processes user keypresses.
 */
class InputHandler {
public:
    /**
     * @brief Constructs an InputHandler object.
     *
     * Initializes the input settings, including enabling special keys like
     * arrow keys and disabling input echo.
     */
    InputHandler();

    /**
     * @brief Destroys the InputHandler object.
     *
     * Cleans up any input-related resources, if necessary.
     */
    ~InputHandler();

    /**
     * @brief Reads a keypress from the user.
     *
     * This function waits for user input, depending on the timeout setting,
     * and returns the corresponding keycode.
     *
     * @return The keycode of the pressed key.
     */
    int getKey();

    /**
     * @brief Sets a timeout for user input.
     *
     * Configures the maximum amount of time (in milliseconds) to wait for
     * user input. If no input is received within this time, `getKey()` will
     * return ERR.
     *
     * @param milliseconds Timeout value in milliseconds.
     */
    void setTimeout(int milliseconds);

    /**
     * @brief Resets the timeout to its default blocking behavior.
     *
     * Disables the input timeout, causing `getKey()` to block indefinitely
     * until a keypress is received.
     */
    void resetTimeout();

    /**
     * @brief Maps a keycode to a predefined KeyAction.
     *
     * Converts a raw keycode (e.g., from `getKey()`) into a corresponding
     * `KeyAction`, such as directional movement or exiting the application.
     *
     * @param key The keycode to map.
     * @return The corresponding KeyAction for the given keycode.
     */
    KeyAction mapKey(int key);
};
