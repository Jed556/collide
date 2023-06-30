#include "display.h"

namespace display {
void init(Vector2 dimension, const char* title) {
    InitWindow((int)dimension.x, (int)dimension.y, title);
}

void close() {
    CloseWindow();
}
}  // namespace display