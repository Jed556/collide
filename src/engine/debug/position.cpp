#include "debug.h"

void Debug::showMousePosition() {
    if (!isActive()) return;

    float yPos = infoPadding.y + numShown * infoSpacing;
    Vector2 mousePosition = GetMousePosition();
    DrawTextEx(font, TextFormat("Mouse: (%07.2f, %07.2f)", mousePosition.x, mousePosition.y),
               {infoPadding.x, yPos}, fontSize, fontSpacing, textColor);
    ++numShown;
}

void Debug::showPosition(Vector2 objectPosition, Vector2 objectSize, bool centered, std::string name) {
    if (!isActive()) return;

    float yPos = infoPadding.y + numShown * infoSpacing;
    if (centered) {
        objectPosition.x += objectSize.x / 2.0f;
        objectPosition.y += objectSize.y / 2.0f;
    }

    std::string format = "%0" + std::to_string(7) + ".2f";
    std::string x = fmt::format(format, objectPosition.x);
    std::string y = fmt::format(format, objectPosition.y);

    DrawTextEx(font, TextFormat("%s: (%07.2f, %07.2f)", name.c_str(), objectPosition.x, objectPosition.y),
               {infoPadding.x, yPos}, fontSize, fontSpacing, textColor);
    ++numShown;
}