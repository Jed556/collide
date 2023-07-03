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
        if (valueOnly)
            keyVal = std::to_string(keys[i]).c_str();
        else
            keyVal = key::name(keys[i]);

        DrawTextEx(font, keyVal, {(numPadding), yPos}, fontSize, fontSpacing, textColor);
        numPadding += MeasureTextEx(font, keyVal, fontSize, fontSpacing).x + listPadding.x;
    }

    if (frameCount == 0) {
        keys.clear();
    }
}