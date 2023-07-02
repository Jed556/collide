#include "display.h"

namespace display {
void showCustomCursor() {
    HideCursor();
    Vector2 mousePosition = GetMousePosition();

    // Method 1
    DrawCircle(mousePosition.x, mousePosition.y, 10, {255, 255, 255, 100});

    // Method 2
    // DrawTexture(texture, mousePosition.x - texture.width / 2, mousePosition.y - texture.height / 2, WHITE);
}
}  // namespace display