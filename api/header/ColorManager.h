/**
* @brief Manages color settings for the API.
 *
 * This class provides functionality to set, use, and reset color pairs
 * in the terminal using ncurses. It is part of the API's utilities
 * for customizing the appearance of text and background.
 */
#pragma once

class ColorManager {
public:

    /**
     * @brief Constructs a new ColorManager object.
     *
     * Initializes the ColorManager. This should be done before using any
     * color-related functions.
     */
    ColorManager();

    /**
     * @brief Defines a new color pair.
     *
     * @param pair The color pair number (0-255, depending on ncurses support).
     * @param fg The foreground color ID.
     * @param bg The background color ID.
     *
     * Colors must be initialized using ncurses `start_color()` before calling
     * this function.
     */
    void setColorPair(short pair, short fg, short bg);

    /**
     * @brief Activates the specified color pair for future text output.
     *
     * @param pair The color pair number to use.
     *
     * Once activated, all subsequent text output will use this color pair
     * until a new pair is set or `resetColor()` is called.
     */
    void useColorPair(short pair);

    /**
     * @brief Resets to the default terminal color settings.
     *
     * This method disables any active color pair and reverts the terminal
     * to its default foreground and background colors.
     */
    void resetColor();
};
