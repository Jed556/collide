#include "display.h"

namespace display {
void init(Vector2 dimension, const char* title, const char* iconPath) {
    Image icon = LoadImage(iconPath);
    InitWindow((int)dimension.x, (int)dimension.y, title);
    SetWindowState(FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_UNDECORATED);
    SetWindowIcon(icon);
}

void close() {
    CloseWindow();
}
}  // namespace display