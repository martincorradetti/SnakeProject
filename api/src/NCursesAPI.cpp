#include "NCursesAPI.h"

// Constructor
NCursesAPI::NCursesAPI()
:windowManager(nullptr), renderer(nullptr), inputHandler(nullptr), colorManager(nullptr)
{
        windowManager = new WindowManager{};
        renderer = new Renderer{};
        inputHandler = new InputHandler{};
        colorManager = new ColorManager{};
}

NCursesAPI::NCursesAPI(bool color)
:windowManager(nullptr), renderer(nullptr), inputHandler(nullptr), colorManager(nullptr)
{
    windowManager = new WindowManager();
    renderer = new Renderer();
    inputHandler = new InputHandler();
    colorManager = color ? new ColorManager() : nullptr;
}

// Destructor
NCursesAPI::~NCursesAPI()
{
    delete windowManager;
    delete renderer;
    delete inputHandler;
    delete colorManager;
}

// Delegated methods
void NCursesAPI::clearScreen(const bool refreshImmediately)
{
    windowManager->clearScreen(refreshImmediately);
}

void NCursesAPI::refreshScreen()
{
    windowManager->refreshScreen();
}

void NCursesAPI::drawBorder()
{
    windowManager->drawBorder();
}

void NCursesAPI::getScreenSize(int &rows, int &cols) const
{
    windowManager->getScreenSize(rows, cols);
}

void NCursesAPI::print(const char ch)
{
	renderer->print(ch);
}

void NCursesAPI::print(const char* text)
{
	renderer->print(text);
}

void NCursesAPI::print(const int y, const int x, const char ch)
{
    renderer->print(y, x, ch);
}

void NCursesAPI::print(const int y, const int x, const char* text)
{
	renderer->print(y, x, text);
}

void NCursesAPI::println(const char ch)
{
    renderer->println(ch);
}

void NCursesAPI::println(const char* text)
{
    renderer->println(text);
}

void NCursesAPI::println(const int y, const int x, const char ch)
{
    renderer->println(y, x, ch);
}

void NCursesAPI::println(const int x, const int y, const char* text) {
    renderer->println(y, x, text);
}

void NCursesAPI::drawRectangle(const int startY, const int startX, const int height, const int width) {
    renderer->drawRectangle(startY, startX, height, width);
}

int NCursesAPI::getKey() {
    return inputHandler->getKey();
}

void NCursesAPI::setInputTimeout(const int milliseconds) {
    inputHandler->setTimeout(milliseconds);
}

void NCursesAPI::resetInputTimeout() {
    inputHandler->resetTimeout();
}

void NCursesAPI::setColorPair(const short pair, const short fg, const short bg) {
    colorManager->setColorPair(pair, fg, bg);
}

void NCursesAPI::useColorPair(const short pair) {
    colorManager->useColorPair(pair);
}

void NCursesAPI::resetColor() {
    colorManager->resetColor();
}
