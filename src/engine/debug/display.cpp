#include "debug.h"

void Debug::showCenter(bool showPoint, bool showCross) {
    if (!isActive()) return;

    if (showPoint) {
        DrawCircle(screenSize.x / 2.0f, screenSize.y / 2.0f, 5, RED);
    }
    if (showCross) {
        DrawLine(screenSize.x / 2, 0, screenSize.x / 2, screenSize.y, RED);
        DrawLine(0, screenSize.y / 2, screenSize.x, screenSize.y / 2, RED);
    }
}

void Debug::showFPS() {
    if (!isActive()) return;

    float yPos = getAndUpdateInfoY();
    DrawTextEx(font, TextFormat("FPS: %i (%i)", GetFPS(), frameCount),
               {infoPadding.x, yPos}, fontSize, fontSpacing, textColor);
}