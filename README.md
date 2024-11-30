
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
cd GameAPI
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
// Simple Hello World
int main()
{
    GameAPI game;

    game.clearScreen();
    game.print("Hello World!");
    game.getKey();
}
```

---

### **`GameAPI`**
The singleton class that centralizes all terminal operations.

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

