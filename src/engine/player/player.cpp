#include "player.h"

void Player::update() {
    prevPosition = position;

    if (IsKeyDown(KEY_D)) position.x += speed;
    if (IsKeyDown(KEY_A)) position.x -= speed;
    if (IsKeyDown(KEY_S)) position.y += speed;
    if (IsKeyDown(KEY_W)) position.y -= speed;
}

bool Player::collide(Vector2 start, Vector2 end) {
    if ((position.x < start.x || position.x + size.x > start.x + end.x) && (position.y < start.y || position.y + size.y > start.y + end.y)) {
        position = prevPosition;
        return true;
    }
    if (position.x < start.x || position.x + size.x > start.x + end.x) {
        position.x = prevPosition.x;
        return true;
    }
    if (position.y < start.y || position.y + size.y > start.y + end.y) {
        position.y = prevPosition.y;
        return true;
    }
    return false;
}

void Player::draw() {
    DrawRectanglePro({position.x, position.y, size.x, size.y}, origin, 0.0f, color);
}