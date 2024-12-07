#include "NCursesAPI.h"

#include <stdexcept>

// Constructor with default color disabled
NCursesAPI::NCursesAPI(const int rows, const int cols)
    : NCursesAPI(rows, cols, false) {}

// Constructor with optional color support
NCursesAPI::NCursesAPI(const int rows, const int cols, const bool color)
    : windowManager(new WindowManager(Screen(rows, cols))),
      renderer(new Renderer(*windowManager)),
      inputHandler(new InputHandler()),
      colorManager(color ? new ColorManager() : nullptr) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Rows and columns must be positive integers.");
    }
}

// Destructor: Clean up resources
NCursesAPI::~NCursesAPI() {
    delete windowManager;
    delete renderer;
    delete inputHandler;
    delete colorManager;
}

// Delegated methods
void NCursesAPI::clearScreen(const bool refreshImmediately) const {
    windowManager->clearScreen(refreshImmediately);
}

void NCursesAPI::refreshScreen() const {
    windowManager->refreshScreen();
}

void NCursesAPI::drawBorder() const {
    windowManager->drawBorder();
}

void NCursesAPI::getScreenSize(int& rows, int& cols) const {
    Screen size = windowManager->getScreenSize();
    rows = size.rows;
    cols = size.cols;
}

void NCursesAPI::print(const int y, const int x, const char ch) const {
    renderer->print(y, x, ch);
}

void NCursesAPI::print(const char* text) const {
    renderer->print(text);
}

void NCursesAPI::print(const char ch) const {
    renderer->print(ch);
}

void NCursesAPI::print(const int y, const int x, const char* text) const {
    renderer->print(y, x, text);
}

void NCursesAPI::println(const int y, const int x, const char ch) const {
    renderer->println(y, x, ch);
}

void NCursesAPI::println(const char* text) const {
    renderer->println(text);
}

void NCursesAPI::println(char ch) const {
    renderer->println(ch);
}

void NCursesAPI::println(const int y, const int x, const char* text) const {
    renderer->println(y, x, text);
}

void NCursesAPI::drawRectangle(const int startY, const int startX, const int height, const int width) const {
    renderer->drawRectangle(startY, startX, height, width);
}

int NCursesAPI::getKey() const {
    return inputHandler->getKey();
}

void NCursesAPI::setInputTimeout(const int milliseconds) const {
    inputHandler->setTimeout(milliseconds);
}

void NCursesAPI::resetInputTimeout() const {
    inputHandler->resetTimeout();
}

void NCursesAPI::setColorPair(const short pair, const short fg, const short bg) const {
    if (colorManager) {
        colorManager->setColorPair(pair, fg, bg);
    }
}

void NCursesAPI::useColorPair(const short pair) const {
    if (colorManager) {
        colorManager->useColorPair(pair);
    }
}

void NCursesAPI::resetColor() const {
    if (colorManager) {
        colorManager->resetColor();
    }
}
