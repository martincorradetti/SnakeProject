#pragma once
#include <ncurses.h>

/**
 * @brief Represents the dimensions of the terminal screen.
 *
 * Encapsulates the immutable number of rows and columns in the terminal screen
 * for use in window management operations.
 */
struct Screen {
    const int rows; /**< Number of rows in the terminal screen. */
    const int cols; /**< Number of columns in the terminal screen. */

    /**
     * @brief Constructs a Screen object with specified dimensions.
     *
     * @param rows The number of rows in the screen.
     * @param cols The number of columns in the screen.
     */
    Screen(const int rows, const int cols)
        : rows(rows), cols(cols) {}
};

/**
 * @brief Manages terminal window operations using ncurses.
 *
 * This class provides functionality to manage the terminal window,
 * including clearing and refreshing the screen, retrieving screen dimensions,
 * and drawing borders. The screen dimensions are passed during construction.
 */
class WindowManager {
private:
    const Screen screen; /**< Stores the screen dimensions. */

public:
    /**
     * @brief Constructs a WindowManager object with specified screen dimensions.
     *
     * Initializes the ncurses library and stores the given screen dimensions.
     *
     * @param screen The screen dimensions to be used by the WindowManager.
     */
    explicit WindowManager(const Screen& screen);

    /**
     * @brief Destroys the WindowManager object.
     *
     * Cleans up ncurses resources and restores the terminal to its
     * original state.
     */
    ~WindowManager();

    /**
     * @brief Clears the terminal screen.
     *
     * Optionally refreshes the screen immediately after clearing.
     *
     * @param refreshImmediately If true, refreshes the screen after clearing.
     */
    void clearScreen(bool refreshImmediately = true);

    /**
     * @brief Refreshes the terminal screen.
     *
     * Updates the terminal display to reflect any changes made to the screen.
     */
    void refreshScreen();

    /**
     * @brief Retrieves the screen dimensions.
     *
     * @return A `const Screen&` containing the number of rows and columns.
     */
    const Screen& getScreenSize() const;

    /**
     * @brief Draws a border around the terminal window.
     *
     * Uses the ncurses `box()` function to create a simple rectangular border.
     */
    void drawBorder();
};
