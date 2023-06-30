#include "display.h"

namespace window {
void setFPS(int fps) {
    if (fps)
        SetTargetFPS(fps);
    else
        SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
}

void init(Vector2 dimension, const char* title) {
    InitWindow((int)dimension.x, (int)dimension.y, title);
}

void close() {
    CloseWindow();
}
}  // namespace display