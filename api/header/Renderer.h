/**
 * @brief Handles rendering operations for the application.
 *
 * This class provides functionality to render text, characters, and shapes
 * such as rectangles on the screen. It is designed for use in terminal-based
 * applications, typically in combination with ncurses.
 */
#pragma once
#include "WindowManager.h"

class Renderer {
private:
    Screen screen; /**< Stores the screen dimensions. */

public:
    /**
     * @brief Constructs a Renderer object with dimensions from a WindowManager.
     *
     * @param wm A reference to the WindowManager object providing screen dimensions.
     */
    Renderer(const WindowManager& wm);

    /**
     * @brief Prints a string of text at the current cursor position.
     *
     * @param text The string to print.
     */
    void print(const char* text);

    /**
     * @brief Prints a character at the current cursor position.
     *
     * @param ch The character to print.
     */
    void print(char ch);

    /**
     * @brief Prints a character at a specified position on the screen.
     *
     * @param y The y-coordinate (row) where the character will be printed.
     * @param x The x-coordinate (column) where the character will be printed.
     * @param ch The character to print.
     */
    void print(int y, int x, char ch);

    /**
     * @brief Prints a string of text at a specified position on the screen.
     *
     * @param y The y-coordinate (row) where the text will start.
     * @param x The x-coordinate (column) where the text will start.
     * @param text The string to print.
     */
    void print(int y, int x, const char* text);

    /**
     * @brief Prints a string of text followed by a newline at the current cursor position.
     *
     * @param text The string to print.
     */
    void println(const char* text);

    /**
     * @brief Prints a character followed by a newline at the current cursor position.
     *
     * @param ch The character to print.
     */
    void println(char ch);

    /**
     * @brief Prints a character followed by a newline at a specified position.
     *
     * @param y The y-coordinate (row) where the character will be printed.
     * @param x The x-coordinate (column) where the character will be printed.
     * @param ch The character to print.
     */
    void println(int y, int x, char ch);

    /**
     * @brief Prints a string of text followed by a newline at a specified position.
     *
     * @param y The y-coordinate (row) where the text will start.
     * @param x The x-coordinate (column) where the text will start.
     * @param text The string to print.
     */
    void println(int y, int x, const char* text);

    /**
     * @brief Draws a rectangle on the screen.
     *
     * @param startY The y-coordinate (row) of the top-left corner.
     * @param startX The x-coordinate (column) of the top-left corner.
     * @param height The height of the rectangle.
     * @param width The width of the rectangle.
     * @param refreshImmediately Whether to refresh the screen immediately after drawing.
     */
    void drawRectangle(int startY, int startX, int height, int width, bool refreshImmediately = true);
};
