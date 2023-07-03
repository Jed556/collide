#include "display.h"

namespace display {
void init(Vector2 dimension, const char* title, const char* iconPath) {
    Image icon = LoadImage(iconPath);
    InitWindow((int)dimension.x, (int)dimension.y, title);
    SetWindowIcon(icon);
}

void close() {
    CloseWindow();
}
}  // namespace display