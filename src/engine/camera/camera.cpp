#include "camera.h"

GameCamera::GameCamera(Vector2 target, Vector2 offset, float rotation, float zoom, float speed) {
    prop.target = target;
    prop.offset = {offset.x + target.x, offset.y + target.y};
    prop.rotation = rotation;
    prop.zoom = zoom;
    this->speed = speed;
}

void GameCamera::update(Vector2 position, EaseType easeType) {
    float normSpeed = math::normSpeed(speed * 5);
    if (easeType == EaseType::None) {
        prop.target = position;
    } else if (easeType == EaseType::Legacy) {
        prop.target.x += (position.x - prop.target.x) * normSpeed;
        prop.target.y += (position.y - prop.target.y) * normSpeed;
    } else {
        float ease = ease::Ease(normSpeed, easeType);
        prop.target.x += (position.x - prop.target.x) * ease;
        prop.target.y += (position.y - prop.target.y) * ease;
        // prop.target.x = Lerp(prop.target.x, position.x, ease);
        // prop.target.y = Lerp(prop.target.y, position.y, ease);
    }
}

void GameCamera::begin() {
    BeginMode2D(prop);
}

void GameCamera::end() {
    EndMode2D();
}