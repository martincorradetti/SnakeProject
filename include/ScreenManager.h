
#pragma once

class ScreenManager {
private:
    int screenRows, screenCols;

public:
    ScreenManager();
    ~ScreenManager();

    static void clearScreen(bool refreshImmediately = true);
    static void refreshScreen();
    void getScreenSize(int &rows, int &cols) const;

    static void drawBorder();
};
