#include "GameAPI.h"

// Initialize the singleton instance
GameAPI& GameAPI::getInstance() {
    static GameAPI instance;
    return instance;
}

// Private constructor
GameAPI::GameAPI() {
    ColorManager::initialize(); // Initialize colors during setup
}

// Delegated methods
void GameAPI::clearScreen(const bool refreshImmediately) {
    ScreenManager::clearScreen(refreshImmediately);
}

void GameAPI::refreshScreen() {
    ScreenManager::refreshScreen();
}

void GameAPI::drawBorder() {
    ScreenManager::drawBorder();
}

void GameAPI::getScreenSize(int &rows, int &cols) const {
    screenManager.getScreenSize(rows, cols);
}

void GameAPI::drawText(const int y, const int x, const std::string &text) {
    Renderer::drawText(y, x, text);
}

void GameAPI::drawChar(const int y, const int x, const char c) {
    Renderer::drawChar(y, x, c);
}

void GameAPI::drawRectangle(const int startY, const int startX, const int height, const int width) {
    Renderer::drawRectangle(startY, startX, height, width);
}

int GameAPI::getKey() {
    return InputHandler::getKey();
}

void GameAPI::setInputTimeout(const int milliseconds) {
    InputHandler::setTimeout(milliseconds);
}

void GameAPI::resetInputTimeout() {
    InputHandler::resetTimeout();
}

void GameAPI::initColors() {
    colorManager.initialize();
}

void GameAPI::setColorPair(const short pair, const short fg, const short bg) {
    colorManager.setColorPair(pair, fg, bg);
}

void GameAPI::useColorPair(const short pair) {
    colorManager.useColorPair(pair);
}

void GameAPI::resetColor() {
    colorManager.resetColor();
}
