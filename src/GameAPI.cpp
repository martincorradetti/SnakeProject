#include "GameAPI.h"

// Constructor
GameAPI::GameAPI() = default;

// Destructor
GameAPI::~GameAPI() = default;

// Delegated methods
void GameAPI::clearScreen(const bool refreshImmediately)
{
    screenManager.clearScreen(refreshImmediately);
}

void GameAPI::refreshScreen()
{
    screenManager.refreshScreen();
}

void GameAPI::drawBorder()
{
    screenManager.drawBorder();
}

void GameAPI::getScreenSize(int &rows, int &cols) const
{
    screenManager.getScreenSize(rows, cols);
}

void GameAPI::print(const char ch)
{
	renderer.print(ch);
}

void GameAPI::print(const char* text)
{
	renderer.print(text);
}

void GameAPI::print(const int y, const int x, const char ch)
{
    renderer.print(y, x, ch);
}

void GameAPI::print(const int y, const int x, const char* text)
{
	renderer.print(y, x, text);
}

void GameAPI::drawRectangle(const int startY, const int startX, const int height, const int width) {
    renderer.drawRectangle(startY, startX, height, width);
}

int GameAPI::getKey() {
    return inputHandler.getKey();
}

void GameAPI::setInputTimeout(const int milliseconds) {
    inputHandler.setTimeout(milliseconds);
}

void GameAPI::resetInputTimeout() {
    inputHandler.resetTimeout();
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
