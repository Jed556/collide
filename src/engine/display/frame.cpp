#include "display.h"

namespace display {
void setFPS(int fps) {
    if (fps)
        SetTargetFPS(fps);
    else
        SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
}
}  // namespace display