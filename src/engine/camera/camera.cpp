#include "camera.h"

void GameCamera::update(Vector2 position, bool ease) {
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