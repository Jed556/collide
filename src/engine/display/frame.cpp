#include "display.h"

namespace display {
void setFPS(int fps) {
    if (fps)
        SetTargetFPS(fps);
    else
        SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
}

int getFrameCount() {
    float deltaTime = GetFrameTime();

    static float elapsedTime = 0.0f;
    static int frames = 0;
    // static int fps = 0;
    elapsedTime += deltaTime;
    frames++;

    if (elapsedTime >= 1.0f) {
        // fps = frames;
        frames = 0;
        elapsedTime -= 1.0f;
    }
    return frames;
}
}  // namespace display