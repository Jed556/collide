#include "debug.h"

Debug::Debug(Vector2 screenSize, Font font) {
    this->screenSize = screenSize;
    this->font = font;
}

void Debug::toggle() {
    debugMode = !debugMode;
}

bool Debug::isActive() {
    return debugMode;
}

void Debug::begin() {
    frameCount = display::getFrameCount();
    numShown = 0;
}

float Debug::getAndUpdateInfoY() {
    float y = numShown * infoSpacing + infoPadding.y;
    ++numShown;
    return y;
}

void Debug::showOverlays(bool showCenterPoint, bool showCenterCross) {
    if (!isActive()) return;

    showFPS();
    showMousePosition();
    showCenter(showCenterPoint, showCenterCross);
}