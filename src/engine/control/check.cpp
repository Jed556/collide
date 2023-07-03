#include "control.h"

namespace key {
bool pressed(int key) {
    return IsKeyPressed(key);
}

bool held(int key) {
    return IsKeyDown(key);
}

bool released(int key) {
    return IsKeyReleased(key);
}

const char* name(int key) {
    const char* name = "None";

    switch (key) {
        // Alphanumeric keys
        case KEY_APOSTROPHE:
            name = "'";
            break;
        case KEY_COMMA:
            name = ",";
            break;
        case KEY_MINUS:
            name = "-";
            break;
        case KEY_PERIOD:
            name = ".";
            break;
        case KEY_SLASH:
            name = "/";
            break;
        case KEY_ZERO:
            name = "0";
            break;
        case KEY_ONE:
            name = "1";
            break;
        case KEY_TWO:
            name = "2";
            break;
        case KEY_THREE:
            name = "3";
            break;
        case KEY_FOUR:
            name = "4";
            break;
        case KEY_FIVE:
            name = "5";
            break;
        case KEY_SIX:
            name = "6";
            break;
        case KEY_SEVEN:
            name = "7";
            break;
        case KEY_EIGHT:
            name = "8";
            break;
        case KEY_NINE:
            name = "9";
            break;
        case KEY_SEMICOLON:
            name = ";";
            break;
        case KEY_EQUAL:
            name = "=";
            break;
        case KEY_A:
            name = "A";
            break;
        case KEY_B:
            name = "B";
            break;
        case KEY_C:
            name = "C";
            break;
        case KEY_D:
            name = "D";
            break;
        case KEY_E:
            name = "E";
            break;
        case KEY_F:
            name = "F";
            break;
        case KEY_G:
            name = "G";
            break;
        case KEY_H:
            name = "H";
            break;
        case KEY_I:
            name = "I";
            break;
        case KEY_J:
            name = "J";
            break;
        case KEY_K:
            name = "K";
            break;
        case KEY_L:
            name = "L";
            break;
        case KEY_M:
            name = "M";
            break;
        case KEY_N:
            name = "N";
            break;
        case KEY_O:
            name = "O";
            break;
        case KEY_P:
            name = "P";
            break;
        case KEY_Q:
            name = "Q";
            break;
        case KEY_R:
            name = "R";
            break;
        case KEY_S:
            name = "S";
            break;
        case KEY_T:
            name = "T";
            break;
        case KEY_U:
            name = "U";
            break;
        case KEY_V:
            name = "V";
            break;
        case KEY_W:
            name = "W";
            break;
        case KEY_X:
            name = "X";
            break;
        case KEY_Y:
            name = "Y";
            break;
        case KEY_Z:
            name = "Z";
            break;
        case KEY_LEFT_BRACKET:
            name = "[";
            break;
        case KEY_BACKSLASH:
            name = "\\";
            break;
        case KEY_RIGHT_BRACKET:
            name = "]";
            break;
        case KEY_GRAVE:
            name = "`";
            break;

        // Function keys
        case KEY_SPACE:
            name = "Space";
            break;
        case KEY_ESCAPE:
            name = "Escape";
            break;
        case KEY_ENTER:
            name = "Enter";
            break;
        case KEY_TAB:
            name = "Tab";
            break;
        case KEY_BACKSPACE:
            name = "Backspace";
            break;
        case KEY_INSERT:
            name = "Insert";
            break;
        case KEY_DELETE:
            name = "Delete";
            break;
        case KEY_RIGHT:
            name = "Right";
            break;
        case KEY_LEFT:
            name = "Left";
            break;
        case KEY_DOWN:
            name = "Down";
            break;
        case KEY_UP:
            name = "Up";
            break;
        case KEY_PAGE_UP:
            name = "Page Up";
            break;
        case KEY_PAGE_DOWN:
            name = "Page Down";
            break;
        case KEY_HOME:
            name = "Home";
            break;
        case KEY_END:
            name = "End";
            break;
        case KEY_CAPS_LOCK:
            name = "Caps Lock";
            break;
        case KEY_SCROLL_LOCK:
            name = "Scroll Lock";
            break;
        case KEY_NUM_LOCK:
            name = "Num Lock";
            break;
        case KEY_PRINT_SCREEN:
            name = "Print Screen";
            break;
        case KEY_PAUSE:
            name = "Pause";
            break;
        case KEY_F1:
            name = "F1";
            break;
        case KEY_F2:
            name = "F2";
            break;
        case KEY_F3:
            name = "F3";
            break;
        case KEY_F4:
            name = "F4";
            break;
        case KEY_F5:
            name = "F5";
            break;
        case KEY_F6:
            name = "F6";
            break;
        case KEY_F7:
            name = "F7";
            break;
        case KEY_F8:
            name = "F8";
            break;
        case KEY_F9:
            name = "F9";
            break;
        case KEY_F10:
            name = "F10";
            break;
        case KEY_F11:
            name = "F11";
            break;
        case KEY_F12:
            name = "F12";
            break;
        case KEY_LEFT_SHIFT:
            name = "Left Shift";
            break;
        case KEY_LEFT_CONTROL:
            name = "Left Control";
            break;
        case KEY_LEFT_ALT:
            name = "Left Alt";
            break;
        case KEY_LEFT_SUPER:
            name = "Left Super";
            break;
        case KEY_RIGHT_SHIFT:
            name = "Right Shift";
            break;
        case KEY_RIGHT_CONTROL:
            name = "Right Control";
            break;
        case KEY_RIGHT_ALT:
            name = "Right Alt";
            break;
        case KEY_RIGHT_SUPER:
            name = "Right Super";
            break;
        case KEY_KB_MENU:
            name = "KB Menu";
            break;

        // Keypad keys
        case KEY_KP_0:
            name = "Keypad 0";
            break;
        case KEY_KP_1:
            name = "Keypad 1";
            break;
        case KEY_KP_2:
            name = "Keypad 2";
            break;
        case KEY_KP_3:
            name = "Keypad 3";
            break;
        case KEY_KP_4:
            name = "Keypad 4";
            break;
        case KEY_KP_5:
            name = "Keypad 5";
            break;
        case KEY_KP_6:
            name = "Keypad 6";
            break;
        case KEY_KP_7:
            name = "Keypad 7";
            break;
        case KEY_KP_8:
            name = "Keypad 8";
            break;
        case KEY_KP_9:
            name = "Keypad 9";
            break;
        case KEY_KP_DECIMAL:
            name = "Keypad .";
            break;
        case KEY_KP_DIVIDE:
            name = "Keypad /";
            break;
        case KEY_KP_MULTIPLY:
            name = "Keypad *";
            break;
        case KEY_KP_SUBTRACT:
            name = "Keypad -";
            break;
        case KEY_KP_ADD:
            name = "Keypad +";
            break;
        case KEY_KP_ENTER:
            name = "Keypad Enter";
            break;
        case KEY_KP_EQUAL:
            name = "Keypad =";
            break;

            // Android keys buttons
            // case KEY_BACK:
            //     name = "Back";
            //     break;
            // case KEY_MENU:
            //     name = "Menu";
            //     break;
            // case KEY_VOLUME_UP:
            //     name = "Volume Up";
            //     break;
            // case KEY_VOLUME_DOWN:
            //     name = "Volume Down";
            //     break;
    }
    return name;
}

bool debug() {
    return IsKeyPressed(KEY_F1);
}
}  // namespace key