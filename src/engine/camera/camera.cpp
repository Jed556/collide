#include "camera.h"

void GameCamera::update(Vector2 position, bool ease) {
    if (ease) {
        prop.target.x += (position.x - prop.target.x) * math::normSpeed(speed);
        prop.target.y += (position.y - prop.target.y) * math::normSpeed(speed);
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