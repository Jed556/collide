#include "camera.h"

void GameCamera::update(Vector2 position, Vector2 size, bool ease, int focus) {
    // Center camera on object
    if (focus == 5) {
        position.x = position.x + size.x / 2.0f;
        position.y = position.y + size.y / 2.0f;
    }

    // Ease camera movement
    if (ease) {
        prop.target.x += (position.x - prop.target.x) * speed;
        prop.target.y += (position.y - prop.target.y) * speed;
    } else {
        prop.target = {position.x, position.y};
    }
}

void GameCamera::begin() {
    BeginMode2D(prop);
}

void GameCamera::end() {
    EndMode2D();
}