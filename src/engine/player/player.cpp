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
    Vector2 newPosition = position;

    if (position.x < start.x) {
        newPosition.x = start.x;
        collided = true;
    } else if (position.x + size.x > start.x + end.x) {
        newPosition.x = start.x + end.x - size.x;
        collided = true;
    }

    if (position.y < start.y) {
        newPosition.y = start.y;
        collided = true;
    } else if (position.y + size.y > start.y + end.y) {
        newPosition.y = start.y + end.y - size.y;
        collided = true;
    }

    if (collided) position = newPosition;
    return collided;
}

void Player::draw() {
    DrawRectanglePro({position.x, position.y, size.x, size.y}, origin, 0.0f, color);
}

Vector2 Player::getHalfSize() {
    return {size.x / 2.0f, size.y / 2.0f};
}