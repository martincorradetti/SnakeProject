
# **GameAPI Documentation**

## **Overview**
`GameAPI` is a high-level C++ abstraction over the `ncurses` library, designed to make terminal-based game development clean, simple, and modern. It encapsulates terminal management, rendering, input handling, and color management, providing developers with an intuitive API.

### **Key Features**
- **Complete ncurses abstraction**: No direct interaction with ncurses functions.
- **Modular Design**: Logical separation of terminal management, rendering, input, and color handling.
- **Developer-Friendly**: Clean and intuitive methods for drawing, input handling, and terminal customization.
- **Singleton Access**: Centralized management via the `GameAPI` singleton class.

---

## **Getting Started**

### **1. Installation**
Clone the repository and link the `ncurses` library:
```bash
git clone https://github.com/drake0x64/gameAPI.git
cd gameAPI
mkdir build && cd build
cmake ..
make
```

### **2. Include in Your Project**
Add the `GameAPI` header to your project:
```cpp
#include "GameAPI.h"
```

### **3. Example Usage**
```cpp
#include "GameAPI.h"

int main() {
    GameAPI& game = GameAPI::getInstance();

    int rows, cols;
    game.getScreenSize(rows, cols);

    bool running = true;
    game.drawBorder();

    while (running) {
        game.clearScreen(false);
        game.useColorPair(1);
        game.drawText(rows / 2, cols / 2 - 5, "Snake Game");
        game.refreshScreen();

        int key = game.getKey();
        if (key == 'q') {
            running = false;
        }

        game.setInputTimeout(100); // Control game speed
    }

    return 0;
}
```

---

## **Class Reference**

### **`GameAPI`**
The singleton class that centralizes all terminal operations.

#### **Methods**

##### **Screen Management**
- `void clearScreen(bool refreshImmediately = true)`
  - Clears the terminal screen. Optionally refreshes immediately.
- `void refreshScreen()`
  - Refreshes the terminal to display updated content.
- `void drawBorder()`
  - Draws a border around the screen.
- `void getScreenSize(int &rows, int &cols)`
  - Retrieves the screen dimensions (`rows` and `cols`).

##### **Rendering**
- `void drawText(int y, int x, const std::string &text)`
  - Draws text at the specified `(y, x)` position.
- `void drawChar(int y, int x, char c)`
  - Draws a single character at the specified `(y, x)` position.
- `void drawRectangle(int startY, int startX, int height, int width)`
  - Draws a rectangle starting at `(startY, startX)` with the specified height and width.

##### **Input Handling**
- `int getKey()`
  - Captures a single keypress from the user.
- `void setInputTimeout(int milliseconds)`
  - Sets the input timeout (non-blocking mode).
- `void resetInputTimeout()`
  - Resets the input mode to blocking.

##### **Color Management**
- `void initColors()`
  - Initializes color mode (if supported by the terminal).
- `void setColorPair(short pair, short fg, short bg)`
  - Defines a color pair using foreground and background colors.
- `void useColorPair(short pair)`
  - Activates the specified color pair.
- `void resetColor()`
  - Resets the current color attributes.

---

## **Example Scenarios**

### **1. Display a Moving Character**
```cpp
#include "GameAPI.h"

int main() {
    GameAPI& game = GameAPI::getInstance();

    int x = 5, y = 5;
    bool running = true;

    while (running) {
        game.clearScreen(false);
        game.drawChar(y, x, '@');
        game.refreshScreen();

        int key = game.getKey();
        switch (key) {
            case KEY_UP:    y--; break;
            case KEY_DOWN:  y++; break;
            case KEY_LEFT:  x--; break;
            case KEY_RIGHT: x++; break;
            case 'q':       running = false; break;
        }
        game.setInputTimeout(100);
    }

    return 0;
}
```

### **2. Colorful Borders and Text**
```cpp
#include "GameAPI.h"

int main() {
    GameAPI& game = GameAPI::getInstance();

    game.initColors();
    game.setColorPair(1, COLOR_GREEN, COLOR_BLACK);
    game.setColorPair(2, COLOR_RED, COLOR_BLACK);

    game.useColorPair(1);
    game.drawBorder();

    game.useColorPair(2);
    game.drawText(10, 10, "Welcome to GameAPI!");

    game.refreshScreen();
    game.getKey(); // Wait for user input to exit
    return 0;
}
```

---

## **Advanced Topics**
### **Error Handling**
- Ensure the terminal supports colors:
```cpp
try {
    game.initColors();
} catch (std::runtime_error &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
}
```

---

## **Future Directions**
- Support for subwindows and HUDs.
- Event-driven input handling.
- Predefined color themes and configuration.

---

## **Contributing**
Feel free to fork the repo and submit pull requests for bug fixes, improvements, or new features. Open an issue for questions or feature requests.

---

## **License**
[![GPLv3 License](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

