
#pragma once

class WindowManager {
private:
    int screenRows, screenCols;

public:
    WindowManager();
    ~WindowManager();

    void clearScreen(bool refreshImmediately = true);
    void refreshScreen();
    void getScreenSize(int &rows, int &cols) const;

    void drawBorder();
};
