#include "camera.h"

GameCamera::GameCamera(Vector2 target, Vector2 offset, float rotation, float zoom, float speed) {
    prop.target = target;
    prop.offset = {offset.x + target.x, offset.y + target.y};
    prop.rotation = rotation;
    prop.zoom = zoom;
    this->speed = speed;
}

void GameCamera::update(Vector2 position, EaseType easeType) {
    float normSpeed = math::normSpeed(speed);
    if (easeType == EaseType::None) {
        prop.target = position;
    } else if (easeType == EaseType::Legacy) {
        prop.target.x += (position.x - prop.target.x) * normSpeed;
        prop.target.y += (position.y - prop.target.y) * normSpeed;
    } else {
        prop.target.x = ease::Ease(normSpeed, easeType, prop.target.x, position.x);
        prop.target.y = ease::Ease(normSpeed, easeType, prop.target.y, position.y);
    }
}

void GameCamera::begin() {
    BeginMode2D(prop);
}

void GameCamera::end() {
    EndMode2D();
}