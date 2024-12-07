#pragma once

#include "WindowManager.h"
#include "Renderer.h"
#include "InputHandler.h"
#include "ColorManager.h"

/**
 * @brief High-level API for ncurses-based applications.
 *
 * Provides an abstraction over ncurses functionality by managing key components
 * such as window management, rendering, input handling, and color settings.
 */
class NCursesAPI {
private:
    WindowManager* windowManager; /**< Manages window-related operations. */
    Renderer* renderer;           /**< Handles rendering tasks. */
    InputHandler* inputHandler;   /**< Manages input settings and key handling. */
    ColorManager* colorManager;   /**< Manages ncurses color settings. */

public:
    /**
     * @brief Constructs the NCursesAPI object.
     *
     * Initializes the underlying components with specified dimensions.
     *
     * @param rows The number of rows for the terminal screen.
     * @param cols The number of columns for the terminal screen.
     */
    NCursesAPI(int rows, int cols);

    /**
     * @brief Constructs the NCursesAPI object with color support.
     *
     * @param rows The number of rows for the terminal screen.
     * @param cols The number of columns for the terminal screen.
     * @param color If true, initializes the color manager for enabling color pairs.
     */
    NCursesAPI(int rows, int cols, bool color);

    /**
     * @brief Destroys the NCursesAPI object.
     *
     * Cleans up all ncurses resources by invoking destructors for underlying components.
     */
    ~NCursesAPI();

    // Public methods (delegated to underlying components)
    void clearScreen(bool refreshImmediately = true) const;
    void refreshScreen() const;
    void drawBorder() const;
    void getScreenSize(int& rows, int& cols) const;
    void print(int y, int x, char ch) const;
    void print(const char* text) const;
    void print(char ch) const;
    void print(int y, int x, const char* text) const;
    void println(int y, int x, char ch) const;
    void println(const char* text) const;
    void println(char ch) const;
    void println(int y, int x, const char* text) const;
    void drawRectangle(int startY, int startX, int height, int width) const;
    int getKey() const;
    void setInputTimeout(int milliseconds) const;
    void resetInputTimeout() const;
    void setColorPair(short pair, short fg, short bg) const;
    void useColorPair(short pair) const;
    void resetColor() const;
};
