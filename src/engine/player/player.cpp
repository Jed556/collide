#include "player.h"

void Player::update() {
    prevPosition = position;

    if (IsKeyDown(KEY_D)) position.x += math::normSpeed(speed);
    if (IsKeyDown(KEY_A)) position.x -= math::normSpeed(speed);
    if (IsKeyDown(KEY_S)) position.y += math::normSpeed(speed);
    if (IsKeyDown(KEY_W)) position.y -= math::normSpeed(speed);
}

bool Player::collide(Vector2 start, Vector2 end) {
    bool collided = false;
    if (position.x < start.x || position.x + size.x > start.x + end.x) {
        position.x = prevPosition.x;
        collided = true;
    }
    if (position.y < start.y || position.y + size.y > start.y + end.y) {
        position.y = prevPosition.y;
        collided = true;
    }
    return collided;
}

void Player::draw() {
    DrawRectanglePro({position.x, position.y, size.x, size.y}, origin, 0.0f, color);
}

Vector2 Player::getHalfSize() {
    return {size.x / 2.0f, size.y / 2.0f};
}