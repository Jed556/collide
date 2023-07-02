#include "debug.h"

void Debug::showKeyPressed() {
    if (!isActive()) return;

    float yPos = infoPadding.y + numShown * infoSpacing;

    static std::vector<int> keys;
    int keyPressed = 0, prevKeyPressed = 0;

    Font font = GetFontDefault(); // Can't read from private member
    Vector2 initTextSize = MeasureTextEx(font, "Key Pressed:", fontSize, fontSpacing);
    DrawTextEx(font, "Key Pressed:", {infoPadding.x, yPos}, fontSize, fontSpacing, textColor);

    // DrawRectangle(infoPadding.x, yPos, initTextSize.x, initTextSize.y, textColor);  // Correct size here
    float numPadding = 135;  // Wrong size if "infoPadding.x + initTextSize.x" is used

    do {
        if (keyPressed != prevKeyPressed && keyPressed != KEY_NULL) {
            prevKeyPressed = keyPressed;
            // std::cout << "INFO: Key Pressed: " << keyPressed << std::endl;
            keys.push_back(keyPressed);
        }
        keyPressed = GetKeyPressed();
    } while (keyPressed != KEY_NULL);

    for (int i = 0; i < keys.size(); ++i) {
        numPadding += MeasureTextEx(font, std::to_string(keys[i]).c_str(), fontSize, fontSpacing).x + (i ? 20 : 0);
        DrawTextEx(font, std::to_string(keys[i]).c_str(), {(numPadding), yPos}, fontSize, fontSpacing, textColor);
    }

    // Debug
    // std::cout << "Text size: " << initTextSize.x << ", " << initTextSize.y << std::endl;
    // std::cout << "NumPad size: " << numPadding << std::endl;

    if (frameCount == 0) {
        keys.clear();
    }

    ++numShown;
}