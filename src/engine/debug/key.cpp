#include "debug.h"

void Debug::showKeyPressed(bool valueOnly) {
    if (!isActive()) return;

    float yPos = getAndUpdateInfoY();

    static std::vector<int> keys;
    int keyPressed = 0, prevKeyPressed = 0;

    Font font = GetFontDefault();  // Can't read from private member
    Vector2 initTextSize = MeasureTextEx(font, "Key Pressed:", fontSize, fontSpacing);
    DrawTextEx(font, "Key Pressed:", {infoPadding.x, yPos}, fontSize, fontSpacing, textColor);

    float numPadding = infoPadding.x + listPadding.x + initTextSize.x;

    do {
        if (keyPressed != prevKeyPressed && keyPressed != KEY_NULL) {
            prevKeyPressed = keyPressed;
            // std::cout << "INFO: Key Pressed: " << keyPressed << std::endl;
            keys.push_back(keyPressed);
        }
        keyPressed = GetKeyPressed();
    } while (keyPressed != KEY_NULL);

    for (int i = 0; i < keys.size(); ++i) {
        const char* keyVal = "";
        if (valueOnly) {
            keyVal = std::to_string(keys[i]).c_str();
        } else {
            switch (keys[i]) {
                // Alphanumeric keys
                case KEY_APOSTROPHE:
                    keyVal = "'";
                    break;
                case KEY_COMMA:
                    keyVal = ",";
                    break;
                case KEY_MINUS:
                    keyVal = "-";
                    break;
                case KEY_PERIOD:
                    keyVal = ".";
                    break;
                case KEY_SLASH:
                    keyVal = "/";
                    break;
                case KEY_ZERO:
                    keyVal = "0";
                    break;
                case KEY_ONE:
                    keyVal = "1";
                    break;
                case KEY_TWO:
                    keyVal = "2";
                    break;
                case KEY_THREE:
                    keyVal = "3";
                    break;
                case KEY_FOUR:
                    keyVal = "4";
                    break;
                case KEY_FIVE:
                    keyVal = "5";
                    break;
                case KEY_SIX:
                    keyVal = "6";
                    break;
                case KEY_SEVEN:
                    keyVal = "7";
                    break;
                case KEY_EIGHT:
                    keyVal = "8";
                    break;
                case KEY_NINE:
                    keyVal = "9";
                    break;
                case KEY_SEMICOLON:
                    keyVal = ";";
                    break;
                case KEY_EQUAL:
                    keyVal = "=";
                    break;
                case KEY_A:
                    keyVal = "A";
                    break;
                case KEY_B:
                    keyVal = "B";
                    break;
                case KEY_C:
                    keyVal = "C";
                    break;
                case KEY_D:
                    keyVal = "D";
                    break;
                case KEY_E:
                    keyVal = "E";
                    break;
                case KEY_F:
                    keyVal = "F";
                    break;
                case KEY_G:
                    keyVal = "G";
                    break;
                case KEY_H:
                    keyVal = "H";
                    break;
                case KEY_I:
                    keyVal = "I";
                    break;
                case KEY_J:
                    keyVal = "J";
                    break;
                case KEY_K:
                    keyVal = "K";
                    break;
                case KEY_L:
                    keyVal = "L";
                    break;
                case KEY_M:
                    keyVal = "M";
                    break;
                case KEY_N:
                    keyVal = "N";
                    break;
                case KEY_O:
                    keyVal = "O";
                    break;
                case KEY_P:
                    keyVal = "P";
                    break;
                case KEY_Q:
                    keyVal = "Q";
                    break;
                case KEY_R:
                    keyVal = "R";
                    break;
                case KEY_S:
                    keyVal = "S";
                    break;
                case KEY_T:
                    keyVal = "T";
                    break;
                case KEY_U:
                    keyVal = "U";
                    break;
                case KEY_V:
                    keyVal = "V";
                    break;
                case KEY_W:
                    keyVal = "W";
                    break;
                case KEY_X:
                    keyVal = "X";
                    break;
                case KEY_Y:
                    keyVal = "Y";
                    break;
                case KEY_Z:
                    keyVal = "Z";
                    break;
                case KEY_LEFT_BRACKET:
                    keyVal = "[";
                    break;
                case KEY_BACKSLASH:
                    keyVal = "\\";
                    break;
                case KEY_RIGHT_BRACKET:
                    keyVal = "]";
                    break;
                case KEY_GRAVE:
                    keyVal = "`";
                    break;

                // Function keys
                case KEY_SPACE:
                    keyVal = "Space";
                    break;
                case KEY_ESCAPE:
                    keyVal = "Escape";
                    break;
                case KEY_ENTER:
                    keyVal = "Enter";
                    break;
                case KEY_TAB:
                    keyVal = "Tab";
                    break;
                case KEY_BACKSPACE:
                    keyVal = "Backspace";
                    break;
                case KEY_INSERT:
                    keyVal = "Insert";
                    break;
                case KEY_DELETE:
                    keyVal = "Delete";
                    break;
                case KEY_RIGHT:
                    keyVal = "Right";
                    break;
                case KEY_LEFT:
                    keyVal = "Left";
                    break;
                case KEY_DOWN:
                    keyVal = "Down";
                    break;
                case KEY_UP:
                    keyVal = "Up";
                    break;
                case KEY_PAGE_UP:
                    keyVal = "Page Up";
                    break;
                case KEY_PAGE_DOWN:
                    keyVal = "Page Down";
                    break;
                case KEY_HOME:
                    keyVal = "Home";
                    break;
                case KEY_END:
                    keyVal = "End";
                    break;
                case KEY_CAPS_LOCK:
                    keyVal = "Caps Lock";
                    break;
                case KEY_SCROLL_LOCK:
                    keyVal = "Scroll Lock";
                    break;
                case KEY_NUM_LOCK:
                    keyVal = "Num Lock";
                    break;
                case KEY_PRINT_SCREEN:
                    keyVal = "Print Screen";
                    break;
                case KEY_PAUSE:
                    keyVal = "Pause";
                    break;
                case KEY_F1:
                    keyVal = "F1";
                    break;
                case KEY_F2:
                    keyVal = "F2";
                    break;
                case KEY_F3:
                    keyVal = "F3";
                    break;
                case KEY_F4:
                    keyVal = "F4";
                    break;
                case KEY_F5:
                    keyVal = "F5";
                    break;
                case KEY_F6:
                    keyVal = "F6";
                    break;
                case KEY_F7:
                    keyVal = "F7";
                    break;
                case KEY_F8:
                    keyVal = "F8";
                    break;
                case KEY_F9:
                    keyVal = "F9";
                    break;
                case KEY_F10:
                    keyVal = "F10";
                    break;
                case KEY_F11:
                    keyVal = "F11";
                    break;
                case KEY_F12:
                    keyVal = "F12";
                    break;
                case KEY_LEFT_SHIFT:
                    keyVal = "Left Shift";
                    break;
                case KEY_LEFT_CONTROL:
                    keyVal = "Left Control";
                    break;
                case KEY_LEFT_ALT:
                    keyVal = "Left Alt";
                    break;
                case KEY_LEFT_SUPER:
                    keyVal = "Left Super";
                    break;
                case KEY_RIGHT_SHIFT:
                    keyVal = "Right Shift";
                    break;
                case KEY_RIGHT_CONTROL:
                    keyVal = "Right Control";
                    break;
                case KEY_RIGHT_ALT:
                    keyVal = "Right Alt";
                    break;
                case KEY_RIGHT_SUPER:
                    keyVal = "Right Super";
                    break;
                case KEY_KB_MENU:
                    keyVal = "KB Menu";
                    break;

                // Keypad keys
                case KEY_KP_0:
                    keyVal = "Keypad 0";
                    break;
                case KEY_KP_1:
                    keyVal = "Keypad 1";
                    break;
                case KEY_KP_2:
                    keyVal = "Keypad 2";
                    break;
                case KEY_KP_3:
                    keyVal = "Keypad 3";
                    break;
                case KEY_KP_4:
                    keyVal = "Keypad 4";
                    break;
                case KEY_KP_5:
                    keyVal = "Keypad 5";
                    break;
                case KEY_KP_6:
                    keyVal = "Keypad 6";
                    break;
                case KEY_KP_7:
                    keyVal = "Keypad 7";
                    break;
                case KEY_KP_8:
                    keyVal = "Keypad 8";
                    break;
                case KEY_KP_9:
                    keyVal = "Keypad 9";
                    break;
                case KEY_KP_DECIMAL:
                    keyVal = "Keypad .";
                    break;
                case KEY_KP_DIVIDE:
                    keyVal = "Keypad /";
                    break;
                case KEY_KP_MULTIPLY:
                    keyVal = "Keypad *";
                    break;
                case KEY_KP_SUBTRACT:
                    keyVal = "Keypad -";
                    break;
                case KEY_KP_ADD:
                    keyVal = "Keypad +";
                    break;
                case KEY_KP_ENTER:
                    keyVal = "Keypad Enter";
                    break;
                case KEY_KP_EQUAL:
                    keyVal = "Keypad =";
                    break;

                    // Android keys buttons
                    // case KEY_BACK:
                    //     keyVal = "Back";
                    //     break;
                    // case KEY_MENU:
                    //     keyVal = "Menu";
                    //     break;
                    // case KEY_VOLUME_UP:
                    //     keyVal = "Volume Up";
                    //     break;
                    // case KEY_VOLUME_DOWN:
                    //     keyVal = "Volume Down";
                    //     break;
            }
        }

        DrawTextEx(font, keyVal, {(numPadding), yPos}, fontSize, fontSpacing, textColor);
        numPadding += MeasureTextEx(font, keyVal, fontSize, fontSpacing).x + listPadding.x;
    }

    if (frameCount == 0) {
        keys.clear();
    }
}