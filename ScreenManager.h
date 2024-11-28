
#pragma once

class ScreenManager {
private:
    int screenRows, screenCols;

public:
    ScreenManager();
    ~ScreenManager();

    void clearScreen(bool refreshImmediately = true);
    void refreshScreen();
    void getScreenSize(int &rows, int &cols) const;

    void drawBorder();
};
