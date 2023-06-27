#include "debug.h"

Debug::Debug(Vector2 screenSize) {
    this->screenSize = screenSize;
}

void Debug::begin() {
    numShown = 0;
}

void Debug::showOverlays(bool showCenterPoint, bool showCenterCross) {
    showCenter(showCenterPoint, showCenterCross);
    showFPS();
}

void Debug::showGrid(Vector2 mapSize, Vector2 tileSize) {
    // Old method
    // for (float y = 0; y < mapSize.y; y += tileSize.y)
    //     for (float x = 0; x < mapSize.x; x += tileSize.x) {
    //         float width = fmin(tileSize.x, mapSize.x - x);
    //         float height = fmin(tileSize.y, mapSize.y - y);
    //         // DrawRectangleV({x, y}, {width, height}, LIGHTGRAY);
    //         DrawRectangleLinesEx({x, y, width, height}, 1, gridColor);
    //     }

    for (float y = 0; y <= mapSize.y; y += tileSize.y)
        DrawLine(0, y, mapSize.x, y, gridColor);
    for (float x = 0; x <= mapSize.x; x += tileSize.x)
        DrawLine(x, 0, x, mapSize.y, gridColor);
}

void Debug::showCenter(bool showPoint, bool showCross) {
    if (showPoint) {
        DrawCircle(screenSize.x / 2.0f, screenSize.y / 2.0f, 5, RED);
    }
    if (showCross) {
        DrawLine(screenSize.x / 2, 0, screenSize.x / 2, screenSize.y, RED);
        DrawLine(0, screenSize.y / 2, screenSize.x, screenSize.y / 2, RED);
    }
}

void Debug::showFPS() {
    float yPos = infoPadding.y + numShown * infoSpacing;
    DrawTextEx(font, TextFormat("FPS: %i", GetFPS()), {infoPadding.x, yPos}, fontSize, fontSpacing, textColor);
    ++numShown;
}

void Debug::showPosition(Vector2 objectPosition, Vector2 objectSize, bool centered, std::string name) {
    float yPos = infoPadding.y + numShown * infoSpacing;
    if (centered) {
        objectPosition.x += objectSize.x / 2.0f;
        objectPosition.y += objectSize.y / 2.0f;
    }

    std::string formatString = "%0" + std::to_string(7) + ".2f";
    std::string x = fmt::format(formatString, objectPosition.x);
    std::string y = fmt::format(formatString, objectPosition.y);

    DrawTextEx(font, TextFormat("%s: (%07.2f, %07.2f)", name.c_str(), objectPosition.x, objectPosition.y),
               {infoPadding.x, yPos}, fontSize, fontSpacing, textColor);
    ++numShown;
}